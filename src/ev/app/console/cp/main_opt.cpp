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
///   File: main_opt.cpp
///
/// Author: $author$
///   Date: 11/8/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_APP_CONSOLE_CP_MAIN_OPT_CPP
#define _EV_APP_CONSOLE_CP_MAIN_OPT_CPP

#ifndef _EV_APP_CONSOLE_CP_MAIN_OPT_HPP
#include "ev/app/console/cp/main_opt.hpp"
class {
#endif // _EV_APP_CONSOLE_CP_MAIN_OPT_HPP

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_to_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((!(optarg[1]) && (EV_CONSOLE_CP_MAIN_TO_OPTARG_DOS_C == (optarg[0])))
                || !(chars_t::compare(optarg, EV_CONSOLE_CP_MAIN_TO_OPTARG_DOS_S))) {
                to_ = to_dos;
            } else {
                if ((!(optarg[1]) && (EV_CONSOLE_CP_MAIN_TO_OPTARG_MAC_C == (optarg[0])))
                    || !(chars_t::compare(optarg, EV_CONSOLE_CP_MAIN_TO_OPTARG_MAC_S))) {
                    to_ = to_mac;
                } else {
                    if ((!(optarg[1]) && (EV_CONSOLE_CP_MAIN_TO_OPTARG_UNIX_C == (optarg[0])))
                        || !(chars_t::compare(optarg, EV_CONSOLE_CP_MAIN_TO_OPTARG_UNIX_S))) {
                        to_ = to_unix;
                    } else {
                        if ((!(optarg[1]) && (EV_CONSOLE_CP_MAIN_TO_OPTARG_NATIVE_C == (optarg[0])))
                            || !(chars_t::compare(optarg, EV_CONSOLE_CP_MAIN_TO_OPTARG_NATIVE_S))) {
                            to_ = to_native;
                        } else {
                            if ((!(optarg[1]) && (EV_CONSOLE_CP_MAIN_TO_OPTARG_SAME_C == (optarg[0])))
                                || !(chars_t::compare(optarg, EV_CONSOLE_CP_MAIN_TO_OPTARG_SAME_S))) {
                                to_ = to_same;
                            } else {
                                if ((!(optarg[1]) && (EV_CONSOLE_CP_MAIN_TO_OPTARG_SHA512_C == (optarg[0])))
                                    || !(chars_t::compare(optarg, EV_CONSOLE_CP_MAIN_TO_OPTARG_SHA512_S))) {
                                    to_ = to_sha512;
                                } else {
                                    if ((!(optarg[1]) && (EV_CONSOLE_CP_MAIN_TO_OPTARG_SHA256_C == (optarg[0])))
                                        || !(chars_t::compare(optarg, EV_CONSOLE_CP_MAIN_TO_OPTARG_SHA256_S))) {
                                        to_ = to_sha256;
                                    } else {
                                        if ((!(optarg[1]) && (EV_CONSOLE_CP_MAIN_TO_OPTARG_SHA1_C == (optarg[0])))
                                            || !(chars_t::compare(optarg, EV_CONSOLE_CP_MAIN_TO_OPTARG_SHA1_S))) {
                                            to_ = to_sha1;
                                        } else {
                                            if ((!(optarg[1]) && (EV_CONSOLE_CP_MAIN_TO_OPTARG_MD5_C == (optarg[0])))
                                                || !(chars_t::compare(optarg, EV_CONSOLE_CP_MAIN_TO_OPTARG_MD5_S))) {
                                                to_ = to_md5;
                                            } else {
                                                err = on_invalid_option_arg
                                                (optval, optarg, optname, optind, argc, argv, env);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_test_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        test_ = true;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_verbose_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        verbose_ = true;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_write_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((!(optarg[1]) && (EV_CONSOLE_CP_MAIN_WRITE_OPTARG_OVERWRITE_C == (optarg[0])))
                || !(chars_t::compare(optarg, EV_CONSOLE_CP_MAIN_WRITE_OPTARG_OVERWRITE_S))) {
                write_ = write_overwrite;
            } else {
                if ((optarg) && (optarg[0])) {
                    if ((!(optarg[1]) && (EV_CONSOLE_CP_MAIN_WRITE_OPTARG_APPEND_C == (optarg[0])))
                        || !(chars_t::compare(optarg, EV_CONSOLE_CP_MAIN_WRITE_OPTARG_APPEND_S))) {
                        write_ = write_append;
                    } else {
                        if ((optarg) && (optarg[0])) {
                            if ((!(optarg[1]) && (EV_CONSOLE_CP_MAIN_WRITE_OPTARG_CREATE_C == (optarg[0])))
                                || !(chars_t::compare(optarg, EV_CONSOLE_CP_MAIN_WRITE_OPTARG_CREATE_S))) {
                                write_ = write_create;
                            } else {
                                err = on_invalid_option_arg
                                (optval, optarg, optname, optind, argc, argv, env);
                            }
                        }
                    }
                }
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        switch(optval) {
        case EV_CONSOLE_CP_MAIN_TO_OPTVAL_C:
            err = on_to_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case EV_CONSOLE_CP_MAIN_TEST_OPTVAL_C:
            err = on_test_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case EV_CONSOLE_CP_MAIN_VERBOSE_OPTVAL_C:
            err = on_verbose_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case EV_CONSOLE_CP_MAIN_WRITE_OPTVAL_C:
            err = on_write_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char* option_usage
    (const char*& optarg, const struct option* longopt) {
        const char* chars = "";
        switch(longopt->val) {
        case EV_CONSOLE_CP_MAIN_TO_OPTVAL_C:
            optarg = EV_CONSOLE_CP_MAIN_TO_OPTARG;
            chars = EV_CONSOLE_CP_MAIN_TO_OPTUSE;
            break;
        case EV_CONSOLE_CP_MAIN_TEST_OPTVAL_C:
            optarg = EV_CONSOLE_CP_MAIN_TEST_OPTARG;
            chars = EV_CONSOLE_CP_MAIN_TEST_OPTUSE;
            break;
        case EV_CONSOLE_CP_MAIN_VERBOSE_OPTVAL_C:
            optarg = EV_CONSOLE_CP_MAIN_VERBOSE_OPTARG;
            chars = EV_CONSOLE_CP_MAIN_VERBOSE_OPTUSE;
            break;
        case EV_CONSOLE_CP_MAIN_WRITE_OPTVAL_C:
            optarg = EV_CONSOLE_CP_MAIN_WRITE_OPTARG;
            chars = EV_CONSOLE_CP_MAIN_WRITE_OPTUSE;
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char* options(const struct option*& longopts) {
        int err = 0;
        static const char* chars = EV_CONSOLE_CP_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            EV_CONSOLE_CP_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* arguments(const char**& args) {
        static const char* _args = EV_CONSOLE_CP_MAIN_ARGS;
        static const char* _argv[3] = {
            EV_CONSOLE_CP_MAIN_ARGV
            0};
        args = _argv;
        return _args;
    }

#ifndef _EV_APP_CONSOLE_CP_MAIN_OPT_HPP
};
#endif // _EV_APP_CONSOLE_CP_MAIN_OPT_HPP

#endif // _EV_APP_CONSOLE_CP_MAIN_OPT_CPP 
