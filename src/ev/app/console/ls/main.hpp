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
///   Date: 10/30/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_APP_CONSOLE_LS_MAIN_HPP
#define _EV_APP_CONSOLE_LS_MAIN_HPP

#include "ev/app/console/ls/main_opt.hpp"
#include "ev/os/os/fs/directory/path.hpp"
#include "ev/os/os/fs/entry.hpp"
#include "ev/fs/path/directory/name.hpp"
#include "ev/fs/path/matchers.hpp"
#include "ev/fs/path/matcher.hpp"
#include "ev/fs/path/match/reader.hpp"
#include "ev/fs/path/match/read/events.hpp"
#include "ev/fs/path/separator.hpp"
#include "ev/crypto/base.hpp"

#define EV_APP_CONSOLE_LS_KB_BLOCKSIZE 32
#define EV_APP_CONSOLE_LS_BLOCKSIZE (EV_APP_CONSOLE_LS_KB_BLOCKSIZE*1024)

#define EV_APP_CONSOLE_LS_BETWEEN " "

#define EV_APP_CONSOLE_LS_SKIP_PATTERNS \
    "*.o;*.obj;._*;" \
    ""

#define EV_APP_CONSOLE_LS_MATCH_PATTERNS \
    "*.h;*.c;*.m;*.hh;*.cc;*.mm;*.hpp;*.cpp;*.hxx;*.cxx;*.H;*.C;*.M;" \
    "*.pro;*.pri;Make*;" \
    ""

#define EV_APP_CONSOLE_LS_SKIP_DIRECTORY_PATTERNS \
    ".*;" \
    ""

#define EV_APP_CONSOLE_LS_MATCH_DIRECTORY_PATTERNS \
    "*;" \
    ""

namespace ev {
namespace app {
namespace console {
namespace ls {

typedef fs::path::matchers main_matchers;
typedef fs::path::match::read::events main_match_events;
typedef xos::base::getopt::main_implement main_implement;
typedef xos::base::getopt::main main_extend;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main
: virtual public main_match_events,
  virtual public main_implement, public main_extend {
public:
    typedef main_implement Implements;
    typedef main_extend Extends;
    typedef Extends::char_t char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main()
    : between_(EV_APP_CONSOLE_LS_BETWEEN),
      match_(EV_APP_CONSOLE_LS_MATCH_PATTERNS),
      skip_(EV_APP_CONSOLE_LS_SKIP_PATTERNS),
      match_directory_(EV_APP_CONSOLE_LS_MATCH_DIRECTORY_PATTERNS),
      skip_directory_(EV_APP_CONSOLE_LS_SKIP_DIRECTORY_PATTERNS),
      name_on_(true), source_on_(true), target_on_(true),
      match_case_on_(true), ln_on_(true),
      block_size_(EV_APP_CONSOLE_LS_BLOCKSIZE) {
    }
    virtual ~main() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef crypto::hash::base hash_t;
    typedef crypto::hash::sha256 sha256_t;
    typedef fs::path::parts path_t;
    typedef fs::entry entry_t;
    typedef io::read::file source_file_t;

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char** argv, char **env) {
        int err = 0;

        if ((optind < argc))
            source_.assign(argv[optind]);

        if ((optind+1 < argc))
            target_.assign(argv[optind+1]);

        if (0 < (source_.length())) {
            os::os::fs::directory::path path;
            if ((path.open(source_.c_str()))) {
                fs::directory::entry* e;
                fs::path::parts p;
                for (e = path.get_first_entry(); e; e = path.get_next_entry()) {
                    p.assign(e->path());
                    on_entry(*e, p, source_, target_);
                }
            }
        } else {
            err = usage(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int after_get_options(int argc, char_t** argv, char_t** env) {
        int err = 0;
        matchers_.read(match_.chars(), match_.length());
        skipers_.read(skip_.chars(), skip_.length());
        directory_matchers_.read(match_directory_.chars(), match_directory_.length());
        directory_skipers_.read(skip_directory_.chars(), skip_directory_.length());
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_directory_entry
    (const fs::directory::entry& e, fs::path::parts& p,
     const string_t& source, const string_t& target) {
        if ((recursive_on_)) {
            const char *pchars, *dchars, *chars;
            size_t plength, dlength, length;

            if (!(e.is_circular())
                 && ((pchars = e.path(plength)) && (0 < plength))
                 && ((chars = e.name(length)) && (0 < length))) {
                fs::path::directory::name directory;
                os::os::fs::directory::path path;

                if ((dchars = e.directory(dlength)) && (0 < dlength))
                    directory.assign(dchars, dlength);

                directory.append(chars, length);

                if ((dchars = directory.chars(dlength)) && (0 < dlength)) {
                    if ((path.open(pchars, dchars))) {
                        fs::directory::entry* e;
                        fs::path::parts p;

                        for (e = path.get_first_entry(); e; e = path.get_next_entry()) {
                            p.assign(e->path());
                            on_entry(*e, p, source_, target_);
                        }
                    }
                }
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_match_file_entry_target
    (const fs::directory::entry& e, const string_t& target) {
        os::os::fs::entry t;
        if ((t.exists_is_type(target.chars(), e.type()))) {
            if (!(all_files_on_)) {
                if ((missing_files_on_)) {
                    return false;
                } else {
                    if ((older_files_on_)) {
                        if ((e.is_newer_than(t))) {
                            return false;
                        }
                    } else {
                        if ((e.is_older_than_or_equal(t))) {
                            return false;
                        }
                    }
                }
            }
            return on_match_file_entry_existing_target(e, t);
        } else {
            if ((existing_files_on_) || (fs::entry_type_none != (t.type())))
                return false;
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_match_file_entry_existing_target
    (const fs::directory::entry& e,
     const os::os::fs::entry& target, bool matched_unequal = true) {
        if ((compare_files_on_)) {
            hash_t* hash = 0;

            if ((hash = this->file_hash())) {
                ssize_t s_size, t_size;

                if (0 < (s_size = this->hash_file(e, *hash, source_block_))) {
                    string_t x;

                    x.assignx(source_block_, s_size);
                    EV_LOG_MESSAGE_INFO("source hash = " << x << "");

                    if (0 < (t_size = this->hash_file(target, *hash, target_block_))) {
                        x.assignx(target_block_, s_size);
                        EV_LOG_MESSAGE_INFO("terget hash = " << x << "");

                        if ((s_size) == (t_size)) {
                            int unequal;
                            if (!(unequal = memcmp(source_block_, target_block_, s_size))) {
                                return !matched_unequal;
                            } else {
                                EV_LOG_MESSAGE_INFO("source hash " << ((0 < unequal)?(">"):("<")) << " target hash");
                            }
                        }
                    }
                }
            } else {
                int unequal;
                if (!(unequal = compare_files(e, target))) {
                    return !matched_unequal;
                }
            }
        }
        return matched_unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual hash_t* file_hash() const {
        //return (hash_t*)(&sha256_);
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_file_entry
    (const fs::directory::entry& e, fs::path::parts& p,
     const string_t& source, const string_t& target) {
        const char_t *chars;
        size_t length;

        if ((chars = target.chars(length)) && (0 < length)) {
            fs::path::directory::name name(chars, length);

            name.append(e.directory());
            name.append(e.name());

            if ((on_match_file_entry_target(e, name))) {
                out(before_.c_str());
                if ((source_on_)) {
                    if ((name_on_)) {
                        out(e.path());
                    } else {
                        out(e.directory());
                    }
                    out(between_.c_str());
                }
                if ((target_on_)) {
                    if ((name_on_)) {
                        out(name.chars());
                    } else {
                        fs::path::directory::name directory(chars, length);
                        directory.append(e.directory());
                        out(directory.chars());
                    }
                }
                out(after_.c_str());
                if ((ln_on_)) {
                    outln();
                }
            }
        } else {
            out(before_.c_str());
            if ((source_on_)) {
                if ((name_on_)) {
                    out(e.path());
                } else {
                    out(e.directory());
                }
            }
            out(after_.c_str());
            if ((ln_on_)) {
                outln();
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_actual_entry
    (const fs::directory::entry& e, fs::path::parts& p,
     const string_t& source, const string_t& target) {
        if (fs::entry_type_directory == (fs::entry_type_directory & e.type())) {
            if (!(directory_skipers_.matches(p))) {
                if ((directory_matchers_.matches(p))) {
                    on_directory_entry(e, p, source, target);
                }
            }
        } else {
            if (fs::entry_type_file == (fs::entry_type_file & e.type())) {
                if (!(skipers_.matches(p))) {
                    if ((matchers_.matches(p))) {
                        on_file_entry(e, p, source, target);
                    }
                }
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_symbolic_link_entry
    (const fs::directory::entry& e, fs::path::parts& p,
     const string_t& source, const string_t& target) {
        if (fs::entry_type_directory == (fs::entry_type_directory & e.type())) {
            if (!(exclude_directory_links_on_)) {
                on_actual_entry(e, p, source, target);
            }
        } else {
            if (fs::entry_type_file == (fs::entry_type_file & e.type())) {
                if (!(exclude_file_links_on_)) {
                    on_actual_entry(e, p, source, target);
                }
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_entry
    (const fs::directory::entry& e, fs::path::parts& p,
     const string_t& source, const string_t& target) {
        if (fs::entry_type_symbolic_link == (fs::entry_type_symbolic_link & e.type())) {
            on_symbolic_link_entry(e, p, source, target);
        } else {
            on_actual_entry(e, p, source, target);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_files(const entry_t& source, const entry_t& target) {
        int unequal = 1;
        const char_t* chars = 0;
        size_t length = 0;

        if ((chars = source.path(length)) && (0 < length)) {
            source_file_t source_file;

            EV_LOG_MESSAGE_INFO("open source file \"" << chars << "\"...");
            if ((source_file.open(chars, source_file.mode_read_binary()))) {
                EV_LOG_MESSAGE_INFO("...opened source file \"" << chars << "\"");

                unequal = compare_files(source_file, target);

                EV_LOG_MESSAGE_INFO("close source file \"" << chars << "\"...");
                if ((source_file.close())) {
                    EV_LOG_MESSAGE_INFO("...closed source file \"" << chars << "\"");
                    return length;
                } else {
                    EV_LOG_MESSAGE_INFO("...failed to close source file \"" << chars << "\"");
                }
            } else {
                EV_LOG_MESSAGE_ERROR("...failed to open source file \"" << chars << "\"");
            }
        }
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_files(source_file_t& source, const entry_t& target) {
        int unequal = 1;
        const char_t* chars = 0;
        size_t length = 0;

        if ((chars = target.path(length)) && (0 < length)) {
            source_file_t target_file;

            EV_LOG_MESSAGE_INFO("open target file \"" << chars << "\"...");
            if ((target_file.open(chars, target_file.mode_read_binary()))) {
                EV_LOG_MESSAGE_INFO("...opened target file \"" << chars << "\"");

                unequal = compare_files(source, target_file);

                EV_LOG_MESSAGE_INFO("close target file \"" << chars << "\"...");
                if ((target_file.close())) {
                    EV_LOG_MESSAGE_INFO("...closed target file \"" << chars << "\"");
                    return length;
                } else {
                    EV_LOG_MESSAGE_INFO("...failed to close target file \"" << chars << "\"");
                }
            } else {
                EV_LOG_MESSAGE_ERROR("...failed to open target file \"" << chars << "\"");
            }
        }
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t hash_file
    (const entry_t& source, hash_t& target, char block[]) {
        const char_t* chars = 0;
        size_t length = 0;

        if ((chars = source.path(length)) && (0 < length)) {
            source_file_t source_file;

            EV_LOG_MESSAGE_INFO("open source file \"" << chars << "\"...");
            if ((source_file.open(chars, source_file.mode_read_binary()))) {
                EV_LOG_MESSAGE_INFO("...opened source file \"" << chars << "\"");

                if (0 < (length = hash_file(source_file, target, block))) {
                }

                EV_LOG_MESSAGE_INFO("close source file \"" << chars << "\"...");
                if ((source_file.close())) {
                    EV_LOG_MESSAGE_INFO("...closed source file \"" << chars << "\"");
                    return length;
                } else {
                    EV_LOG_MESSAGE_INFO("...failed to close source file \"" << chars << "\"");
                }
            } else {
                EV_LOG_MESSAGE_ERROR("...failed to open source file \"" << chars << "\"");
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_files(source_file_t& source, source_file_t& target) {
        int unequal = 0;
        for (ssize_t s_amount = 0, t_amount = 0; 0 <= s_amount; ) {
            if (0 < (s_amount = source.read(source_block_, block_size_))) {
                if (0 < (t_amount = target.read(target_block_, block_size_))) {
                    if (s_amount < t_amount) {
                        return unequal = -1;
                    } else {
                        if (s_amount > t_amount) {
                            return unequal = 1;
                        } else {
                            if ((unequal = memcmp(source_block_, target_block_, s_amount))) {
                                return unequal;
                            }
                        }
                    }
                } else {
                    return unequal = 1;
                }
            } else {
                if (0 < (t_amount = target.read(target_block_, block_size_))) {
                    return unequal = -1;
                }
            }
            break;
        }
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t hash_file
    (source_file_t& source, hash_t& target, char block[]) {
        if (0 <= (target.initialize())) {
            for (ssize_t count = 0, amount = 0; 0 <= amount; count += amount) {
                if (0 < (amount = source.read(block, block_size_))) {
                    if (amount != (target.hash(block, amount))) {
                        return 0;
                    } else {
                        continue;
                    }
                } else {
                    if (0 > (amount)) {
                        return 0;
                    }
                }
                if (0 < (count = target.finalize(block, block_size_))) {
                    return count;
                }
                break;
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
#include "ev/app/console/ls/main_opt.cpp"

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    sha256_t sha256_;

    main_matchers matchers_, skipers_;
    main_matchers directory_matchers_, directory_skipers_;
    string_t source_, target_;
    string_t before_directory_, after_directory_, between_directory_;
    string_t before_, after_, between_;
    string_t match_, skip_, match_file_, skip_file_;
    string_t match_directory_, skip_directory_, match_directory_file_, skip_directory_file_;

    bool_t name_on_, directory_on_, directory_only_on_;
    bool_t source_on_, target_on_, reverse_on_, recursive_on_, reflective_on_;
    bool_t match_case_on_, compare_files_on_;
    bool_t existing_files_on_, missing_files_on_, older_files_on_, all_files_on_;
    bool_t exclude_directory_links_on_, exclude_file_links_on_;
    bool_t ln_on_;

    size_t block_size_;
    char source_block_[EV_APP_CONSOLE_LS_BLOCKSIZE],
         target_block_[EV_APP_CONSOLE_LS_BLOCKSIZE];
};

} // namespace ls 
} // namespace console 
} // namespace app 
} // namespace ev 

#endif // _EV_APP_CONSOLE_LS_MAIN_HPP 
