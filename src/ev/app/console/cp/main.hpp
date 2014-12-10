///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main.hpp
///
/// Author: $author$
///   Date: 11/8/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_APP_CONSOLE_CP_MAIN_HPP
#define _EV_APP_CONSOLE_CP_MAIN_HPP

#include "ev/app/console/cp/main_opt.hpp"
#include "ev/os/os/fs/entry.hpp"
#include "ev/fs/entry.hpp"
#include "ev/fs/path/parts.hpp"
#include "ev/crypto/base.hpp"

#include <deque>

#define EV_APP_CONSOLE_CP_MAIN_KB_BLOCKSIZE 64
#define EV_APP_CONSOLE_CP_MAIN_BLOCKSIZE (EV_APP_CONSOLE_CP_MAIN_KB_BLOCKSIZE*1024)

namespace ev {
namespace app {
namespace console {
namespace cp {

typedef ev::console::main_implement main_implement;
typedef ev::console::main main_extend;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implement, public main_extend {
public:
    typedef main_implement Implements;
    typedef main_extend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main()
    : write_(write_create), to_(to_same),
      block_size_(EV_APP_CONSOLE_CP_MAIN_BLOCKSIZE) {
    }
    virtual ~main() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef crypto::hash::base hash_t;
    typedef crypto::hash::md5 md5_t;
    typedef crypto::hash::sha1 sha1_t;
    typedef crypto::hash::sha256 sha256_t;
    typedef crypto::hash::sha512 sha512_t;
    typedef fs::path::parts path_t;
    typedef os::os::fs::entry entry_t;
    typedef io::read::file source_file_t;
    typedef io::write::file target_file_t;
    enum write_t {
        write_create,
        write_overwrite,
        write_append
    };
    enum to_t {
        to_same,
        to_dos,
        to_mac,
        to_unix,
        to_native,
        to_sha512,
        to_sha256,
        to_sha1,
        to_md5
    };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    struct sub_directory_t {
        const char_t* chars;
        size_t length;
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        sub_directory_t
        (const sub_directory_t& copy)
        : chars(copy.chars), length(copy.length) {}
        sub_directory_t
        (const char_t* chars, size_t length)
        : chars(chars), length(length) {}
    };
    typedef std::deque<sub_directory_t> sub_directories_t;

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 1;

        if ((optind < argc) && (argv)) {

            source_path_.assign(argv[optind]);
            if ((optind+1 < argc)) {

                target_path_.assign(argv[optind+1]);
                switch (to_) {
                case to_md5:
                    err = copy_to_hash(source_path_, target_path_, md5_);
                    break;
                case to_sha1:
                    err = copy_to_hash(source_path_, target_path_, sha1_);
                    break;
                case to_sha256:
                    err = copy_to_hash(source_path_, target_path_, sha256_);
                    break;
                case to_sha512:
                    err = copy_to_hash(source_path_, target_path_, sha512_);
                    break;
                default:
                    err = copy(source_path_, target_path_);
                    break;
                }
            } else {
                switch (to_) {
                case to_md5:
                    err = copy_to_hash(source_path_, md5_);
                    break;
                case to_sha1:
                    err = copy_to_hash(source_path_, sha1_);
                    break;
                case to_sha256:
                    err = copy_to_hash(source_path_, sha256_);
                    break;
                case to_sha512:
                    err = copy_to_hash(source_path_, sha512_);
                    break;
                default:
                    err = missing_argument(EV_CONSOLE_CP_MAIN_TARGET_ARG);
                    usage(argc, argv, env);
                    break;
                }
            }
        } else {
            err = missing_argument(EV_CONSOLE_CP_MAIN_SOURCE_ARG);
            usage(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int copy_to_hash(const path_t& source, hash_t& target) {
        entry_t& entry = source_entry_;
        const char_t* chars = 0;
        int err = 0;

        if ((entry.exists(chars = source.chars()))) {
            fs::entry_type type = fs::entry_type_none;

            switch (type = entry.type()) {
            case fs::entry_type_file:
                err = copy_file_to_hash(entry, target);
                break;
            default:
                break;
            }
        } else {
            errf("source file \"%s\" does not exist\n", chars);
            err = 1;
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int copy_file_to_hash(const entry_t& source, hash_t& target) {
        const char_t* chars = 0;
        size_t length = 0;
        int err = 1;
        if ((chars = source.path(length)) && (0 < length)) {
            source_file_t source_file;

            EV_LOG_MESSAGE_INFO("open source file \"" << chars << "\"...");
            if ((source_file.open(chars, source_file.mode_read_binary()))) {
                EV_LOG_MESSAGE_INFO("...opened source file \"" << chars << "\"");

                err = copy_file_to_hash(source_file, target);

                EV_LOG_MESSAGE_INFO("close source file \"" << chars << "\"...");
                if ((source_file.close())) {
                    EV_LOG_MESSAGE_INFO("...closed source file \"" << chars << "\"");
                } else {
                    EV_LOG_MESSAGE_INFO("...failed to close source file \"" << chars << "\"");
                }
            } else {
                EV_LOG_MESSAGE_ERROR("...failed to open source file \"" << chars << "\"");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int copy_file_to_hash(source_file_t& source, hash_t& target) {
        int err = 1;
        if (0 <= (target.initialize())) {
            err = 0;
            for (ssize_t count = 0, amount = 0; 0 <= amount; count += amount) {
                if (0 < (amount = source.read(block_, block_size_))) {
                    if (amount != (target.hash(block_, amount))) {
                        err = 1;
                    } else {
                        continue;
                    }
                } else {
                    if (0 > (amount)) {
                        err = 1;
                    }
                }
                if (!(err)) {
                    if (0 < (count = target.finalize(block_, block_size_))) {
                        outxln(block_, count);
                    } else {
                        err = 1;
                    }
                }
                break;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int copy(const path_t& source, const path_t& target) {
        entry_t& entry = source_entry_;
        const char_t* chars = 0;
        int err = 0;

        if ((entry.exists(chars = source.chars()))) {
            fs::entry_type type = fs::entry_type_none;

            switch (type = entry.type()) {
            case fs::entry_type_file:
                err = copy_file(entry, target);
                break;
            default:
                break;
            }
        } else {
            errf("source file \"%s\" does not exist\n", chars);
            err = 1;
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int copy_file(const entry_t& source, const path_t& target) {
        entry_t& entry = target_entry_;
        const char_t* chars = 0;
        int err = 1;

        if ((entry.exists(chars = target.chars()))) {
            if ((write_overwrite != write_) && (write_append != write_)) {
                errf("target file \"%s\" already exists\n", chars);
            } else {
                fs::entry_type type = fs::entry_type_none;

                switch (type = entry.type()) {
                case fs::entry_type_file:
                    err = copy_file_to_file(source, entry);
                    break;
                default:
                    break;
                }
            }
        } else {
            if (!(err = make_directory(entry, target))) {
                entry.set_path(chars);
                err = copy_file_to_file(source, entry);
            } else {
                errf("failed to make directory \"%s\"\n", target.directory().chars());
            }
        }
        if (!(err) && (!(to_same != to_) || !(target_modified_))) {
            if ((entry.set_times_to_set(source))) {
                if ((entry.set_times_set())) {
                } else {
                }
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int copy_file_to_file(const entry_t& source, const entry_t& target) {
        const char_t* chars = 0;
        size_t length = 0;
        int err = 1;

        if ((chars = source.path(length)) && (0 < length)) {
            source_file_t source_file;

            EV_LOG_MESSAGE_INFO("open source file \"" << chars << "\"...");
            if ((source_file.open(chars, source_file.mode_read_binary()))) {
                EV_LOG_MESSAGE_INFO("...opened source file \"" << chars << "\"");

                err = copy_file_to_file(source_file, target);

                EV_LOG_MESSAGE_INFO("close source file \"" << chars << "\"...");
                if ((source_file.close())) {
                    EV_LOG_MESSAGE_INFO("...closed source file \"" << chars << "\"");
                } else {
                    EV_LOG_MESSAGE_INFO("...failed to close source file \"" << chars << "\"");
                }
            } else {
                EV_LOG_MESSAGE_ERROR("...failed to open source file \"" << chars << "\"");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int copy_file_to_file(source_file_t& source, const entry_t& target) {
        const char_t* chars = 0;
        size_t length = 0;
        int err = 1;

        if ((chars = target.path(length)) && (0 < length)) {
            target_file_t target_file;

            EV_LOG_MESSAGE_INFO("open target file \"" << chars << "\"...");
            if ((target_file.open
                 (chars, (write_overwrite != write_)
                  ?(target_file.mode_append_binary())
                  :(target_file.mode_write_binary())))) {
                EV_LOG_MESSAGE_INFO("...opened target file \"" << chars << "\"");

                err = copy_file_to_file(source, target_file);

                EV_LOG_MESSAGE_INFO("close target file \"" << chars << "\"...");
                if ((target_file.close())) {
                    EV_LOG_MESSAGE_INFO("...closed target file \"" << chars << "\"");
                } else {
                    EV_LOG_MESSAGE_INFO("...failed to close target file \"" << chars << "\"");
                }
            } else {
                EV_LOG_MESSAGE_ERROR("...failed to open target file \"" << chars << "\"");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int copy_file_to_file(source_file_t& source, target_file_t& target) {
        int err = 0;

        switch (to_) {
        case to_dos:
            err = copy_file_to_dos_file(source, target);
            break;
        case to_mac:
            err = copy_file_to_mac_file(source, target);
            break;
        case to_unix:
            err = copy_file_to_unix_file(source, target);
            break;
        case to_native:
#if defined(WINDOWS)
            err = copy_file_to_dos_file(source, target);
#else // defined(WINDOWS)
            err = copy_file_to_unix_file(source, target);
#endif // defined(WINDOWS)
            break;
        default:
            for (ssize_t count = 0, amount = 0; 0 <= amount; count += amount) {
                if (0 < (amount = source.read(block_, block_size_))) {
                    if (amount != (target.write(block_, amount))) {
                        err = 1;
                    } else {
                        continue;
                    }
                } else {
                    if (0 > (amount)) {
                        err = 1;
                    }
                }
                break;
            }
            break;
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int copy_file_to_dos_file(source_file_t& source, target_file_t& target) {
        int err = 0;
        char cr = '\r';
        char lf = 0;
        ssize_t count = 0;

        target_modified_ = false;
        for (ssize_t amount = 0; 0 <= amount; count += amount) {
            if (0 < (amount = source.read(block_, block_size_))) {
                for (ssize_t i = 0; i < amount; ++i) {
                    switch (block_[i]) {
                    case '\r':
                        if (lf) {
                            // <cr><cr>
                            EV_LOG_MESSAGE_INFO("...adding <lf> at " << (count+i));
                            if (1 != (target.write(&lf, 1))) {
                                return err = 1;
                            }
                            target_modified_ = true;
                        }
                        lf = '\n';
                        if (1 != (target.write(block_ + i, 1))) {
                            return err = 1;
                        }
                        break;
                    case '\n':
                        if (lf) {
                            // <cr><lf>
                            EV_LOG_MESSAGE_INFO("...<cr><lf> at " << (count+i));
                            lf = 0;
                        } else {
                            // <lf>
                            EV_LOG_MESSAGE_INFO("...adding <cr> at " << (count+i));
                            if (1 != (target.write(&cr, 1))) {
                                return err = 1;
                            }
                            target_modified_ = true;
                        }
                        if (1 != (target.write(block_ + i, 1))) {
                            return err = 1;
                        }
                        break;
                    default:
                        if (lf) {
                            // <cr>A
                            EV_LOG_MESSAGE_INFO("...adding <lf> at " << (count+i));
                            if (1 != (target.write(&lf, 1))) {
                                return err = 1;
                            }
                            target_modified_ = true;
                            lf = 0;
                        }
                        if (1 != (target.write(block_ + i, 1))) {
                            return err = 1;
                        }
                        break;
                    }
                }
                continue;
            } else {
                if (0 > (amount)) {
                    err = 1;
                }
            }
            break;
        }
        if (lf) {
            // <cr><eof>
            EV_LOG_MESSAGE_INFO("...adding <lf> at " << (count));
            if (1 != (target.write(&lf, 1))) {
                err = 1;
            }
            target_modified_ = true;
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int copy_file_to_mac_file(source_file_t& source, target_file_t& target) {
        int err = 0;
        char cr = '\r';
        char lf = 0;
        ssize_t count = 0;

        target_modified_ = false;
        for (ssize_t amount = 0; 0 <= amount; count += amount) {
            if (0 < (amount = source.read(block_, block_size_))) {
                for (ssize_t i = 0; i < amount; ++i) {
                    switch (block_[i]) {
                    case '\r':
                        if (lf) {
                            // <cr><cr>
                            EV_LOG_MESSAGE_INFO("...<cr><cr> at " << (count+i));
                        }
                        lf = '\n';
                        if (1 != (target.write(block_ + i, 1))) {
                            return err = 1;
                        }
                        break;
                    case '\n':
                        if (lf) {
                            // <cr><lf>
                            EV_LOG_MESSAGE_INFO("...removing <lf> at " << (count+i));
                            lf = 0;
                        } else {
                            // <lf>
                            EV_LOG_MESSAGE_INFO("...adding <cr> at " << (count+i));
                            if (1 != (target.write(&cr, 1))) {
                                return err = 1;
                            }
                        }
                        target_modified_ = true;
                        break;
                    default:
                        if (lf) {
                            // <cr>A
                            lf = 0;
                        }
                        if (1 != (target.write(block_ + i, 1))) {
                            return err = 1;
                        }
                        break;
                    }
                }
                continue;
            } else {
                if (0 > (amount)) {
                    err = 1;
                }
            }
            break;
        }
        if (lf) {
            // <cr><eof>
            EV_LOG_MESSAGE_INFO("...<cr><eof> at " << (count));
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int copy_file_to_unix_file(source_file_t& source, target_file_t& target) {
        int err = 0;
        char cr = 0;
        char lf = '\n';
        ssize_t count = 0;

        target_modified_ = false;
        for (ssize_t amount = 0; 0 <= amount; count += amount) {
            if (0 < (amount = source.read(block_, block_size_))) {
                for (ssize_t i = 0; i < amount; ++i) {
                    switch (block_[i]) {
                    case '\r':
                        if (cr) {
                            // <cr><cr>
                            EV_LOG_MESSAGE_INFO("...adding <lf> at " << (count+i));
                            if (1 != (target.write(&lf, 1))) {
                                return err = 1;
                            }
                        }
                        cr = '\r';
                        target_modified_ = true;
                        break;
                    case '\n':
                        if (cr) {
                            // <cr><lf>
                            EV_LOG_MESSAGE_INFO("...removing <cr> at " << (count+i));
                            target_modified_ = true;
                            cr = 0;
                        }
                        if (1 != (target.write(block_ + i, 1))) {
                            return err = 1;
                        }
                        break;
                    default:
                        if (cr) {
                            // <cr>A
                            EV_LOG_MESSAGE_INFO("...adding <lf> at " << (count+i));
                            if (1 != (target.write(&lf, 1))) {
                                return err = 1;
                            }
                            target_modified_ = true;
                            cr = 0;
                        }
                        if (1 != (target.write(block_ + i, 1))) {
                            return err = 1;
                        }
                        break;
                    }
                }
                continue;
            } else {
                if (0 > (amount)) {
                    err = 1;
                }
            }
            break;
        }
        if (cr) {
            // <cr><eof>
            EV_LOG_MESSAGE_INFO("...adding <lf> at " << (count));
            if (1 != (target.write(&lf, 1))) {
                err = 1;
            }
            target_modified_ = true;
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int copy_to_hash
    (const path_t& source, const path_t& target, hash_t& hash) {
        entry_t& entry = source_entry_;
        const char_t* chars = 0;
        int err = 0;

        if ((entry.exists(chars = source.chars()))) {
            fs::entry_type type = fs::entry_type_none;

            switch (type = entry.type()) {
            case fs::entry_type_file:
                err = copy_file_to_hash(entry, target, hash);
                break;
            default:
                break;
            }
        } else {
            errf("source file \"%s\" does not exist\n", chars);
            err = 1;
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int copy_file_to_hash
    (const entry_t& source, const path_t& target, hash_t& hash) {
        entry_t& entry = target_entry_;
        string_t target_path(target.chars());
        const char_t* chars = 0;
        int err = 1;

        if ((append_hash_name_to_target_path_) && (chars = hash.name())) {
            target_path.append(&target.extension_separator(), 1);
            target_path.append(hash_name_prefix_);
            target_path.append(chars);
            target_path.append(hash_name_suffix_);
        }

        if ((entry.exists(chars = target_path.chars()))) {
            if ((write_overwrite != write_) && (write_append != write_)) {
                errf("target file \"%s\" already exists\n", chars);
            } else {
                fs::entry_type type = fs::entry_type_none;

                switch (type = entry.type()) {
                case fs::entry_type_file:
                    err = copy_file_to_file_hash(source, entry, hash);
                    break;
                default:
                    break;
                }
            }
        } else {
            if (!(err = make_directory(entry, target))) {
                entry.set_path(chars);
                err = copy_file_to_file_hash(source, entry, hash);
            } else {
                errf("failed to make directory \"%s\"\n", target.directory().chars());
            }
        }
        if (!(err) && (!(to_same != to_) || !(target_modified_))) {
            if ((entry.set_times_to_set(source))) {
                if ((entry.set_times_set())) {
                } else {
                }
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int copy_file_to_file_hash
    (const entry_t& source, const entry_t& target, hash_t& hash) {
        const char_t* chars = 0;
        size_t length = 0;
        int err = 1;

        if ((chars = source.path(length)) && (0 < length)) {
            source_file_t source_file;

            EV_LOG_MESSAGE_INFO("open source file \"" << chars << "\"...");
            if ((source_file.open(chars, source_file.mode_read_binary()))) {
                EV_LOG_MESSAGE_INFO("...opened source file \"" << chars << "\"");

                err = copy_file_to_file_hash(source_file, target, hash);

                EV_LOG_MESSAGE_INFO("close source file \"" << chars << "\"...");
                if ((source_file.close())) {
                    EV_LOG_MESSAGE_INFO("...closed source file \"" << chars << "\"");
                } else {
                    EV_LOG_MESSAGE_INFO("...failed to close source file \"" << chars << "\"");
                }
            } else {
                EV_LOG_MESSAGE_ERROR("...failed to open source file \"" << chars << "\"");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int copy_file_to_file_hash
    (source_file_t& source, const entry_t& target, hash_t& hash) {
        const char_t* chars = 0;
        size_t length = 0;
        int err = 1;

        if ((chars = target.path(length)) && (0 < length)) {
            target_file_t target_file;

            EV_LOG_MESSAGE_INFO("open target file \"" << chars << "\"...");
            if ((target_file.open
                 (chars, (write_overwrite != write_)
                  ?(target_file.mode_append_binary())
                  :(target_file.mode_write_binary())))) {
                EV_LOG_MESSAGE_INFO("...opened target file \"" << chars << "\"");

                err = copy_file_to_file_hash(source, target_file, hash);

                EV_LOG_MESSAGE_INFO("close target file \"" << chars << "\"...");
                if ((target_file.close())) {
                    EV_LOG_MESSAGE_INFO("...closed target file \"" << chars << "\"");
                } else {
                    EV_LOG_MESSAGE_INFO("...failed to close target file \"" << chars << "\"");
                }
            } else {
                EV_LOG_MESSAGE_ERROR("...failed to open target file \"" << chars << "\"");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int copy_file_to_file_hash
    (source_file_t& source, target_file_t& target, hash_t& hash) {
        int err = 1;
        if (0 <= (hash.initialize())) {
            err = 0;
            for (ssize_t count = 0, amount = 0; 0 <= amount; count += amount) {
                if (0 < (amount = source.read(block_, block_size_))) {
                    if (amount != (hash.hash(block_, amount))) {
                        err = 1;
                    } else {
                        continue;
                    }
                } else {
                    if (0 > (amount)) {
                        err = 1;
                    }
                }
                if (!(err)) {
                    if (0 < (count = hash.finalize(block_, block_size_))) {
                        if (count > (target.writexln(block_, count))) {
                            err = 1;
                        }
                    } else {
                        err = 1;
                    }
                }
                break;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int make_directory(entry_t& entry, const path_t& path) {
        const char_t* chars = 0;
        size_t length = 0;
        int err = 1;

        if ((chars = path.directory().chars(length)) && (0 < length)) {
            const char_t* dchars = chars;
            size_t dlength = length;
            sub_directories_t sub_directories;

            EV_LOG_MESSAGE_INFO("make directory \"" << chars << "\"...");
            for (bool exists = false; !exists; ) {
                string_t directory(dchars, dlength);

                EV_LOG_MESSAGE_INFO("directory \"" << directory.chars() << "\" exists?...");
                if (!(exists = entry.exists(directory.chars()))) {
                    sub_directory_t sub_directory(dchars, dlength);

                    EV_LOG_MESSAGE_INFO("...directory \"" << directory.chars() << "\" does not exist");
                    sub_directories.push_front(sub_directory);
                    if ((dchars = parent_directory(dchars, dlength, path))) {
                        continue;
                    }
                } else {
                    EV_LOG_MESSAGE_INFO("...directory \"" << directory.chars() << "\" exists");
                }
                break;
            }
            err = make_directories(sub_directories, entry, path);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int make_directories
    (const sub_directories_t& sub_directories, const entry_t& entry, const path_t& path) {
        int err = 0;
        sub_directories_t::const_iterator end = sub_directories.end();
        sub_directories_t::const_iterator i;

        for (i = sub_directories.begin(); i != end; ++i) {
            const sub_directory_t& d = *i;
            string_t path(d.chars, d.length);

            EV_LOG_MESSAGE_INFO("make directory \"" << path << "\"...");
            if ((entry.make_directory(path.chars()))) {
                EV_LOG_MESSAGE_INFO("...made directory \"" << path << "\"");
            } else {
                EV_LOG_MESSAGE_INFO("...failed to make directory \"" << path << "\"");
                return 1;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* parent_directory
    (const char_t* chars, size_t& length, const path_t& path) {
        if ((chars) && (length)) {
            const char_t separator = (char_t)(path.directory_separator());
            size_t dlength = length-1;
            const char_t* dchars = chars + dlength;
            char_t c;

            for (; dchars != chars; --dchars, --dlength) {
                if (separator == (c = *dchars)) {
                    length = dlength;
                    return chars;
                }
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
#include "ev/app/console/cp/main_opt.cpp"

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    md5_t md5_;
    sha1_t sha1_;
    sha256_t sha256_;
    sha512_t sha512_;
    path_t source_path_, target_path_;
    entry_t source_entry_, target_entry_;
    bool_t target_modified_;
    write_t write_;
    to_t to_;
    bool_t verbose_, test_;
    bool_t append_hash_name_to_target_path_;
    string_t hash_name_prefix_, hash_name_suffix_;
    size_t block_size_;
    char block_[EV_APP_CONSOLE_CP_MAIN_BLOCKSIZE];
};

} // namespace cp 
} // namespace console 
} // namespace app 
} // namespace ev 

#endif // _EV_APP_CONSOLE_CP_MAIN_HPP 
