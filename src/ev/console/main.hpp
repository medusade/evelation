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
#ifndef _EV_CONSOLE_MAIN_HPP
#define _EV_CONSOLE_MAIN_HPP

#include "ev/console/main_opt.hpp"
#include "xos/base/getopt/main.hpp"
#include "xos/base/main.hpp"

#define EV_CONSOLE_MAIN_DEBUG_LEVELS_OPT "db"
#define EV_CONSOLE_MAIN_DEBUG_LEVELS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define EV_CONSOLE_MAIN_DEBUG_LEVELS_OPTARG_RESULT 0
#define EV_CONSOLE_MAIN_DEBUG_LEVELS_OPTARG EV_MAIN_LOGGING_OPTARG
#define EV_CONSOLE_MAIN_DEBUG_LEVELS_OPTUSE EV_MAIN_LOGGING_OPTUSE
#define EV_CONSOLE_MAIN_DEBUG_LEVELS_OPTVAL_S "d:"
#define EV_CONSOLE_MAIN_DEBUG_LEVELS_OPTVAL_C 'd'
#define EV_CONSOLE_MAIN_DEBUG_LEVELS_OPTION \
   {EV_CONSOLE_MAIN_DEBUG_LEVELS_OPT, \
    EV_CONSOLE_MAIN_DEBUG_LEVELS_OPTARG_REQUIRED, \
    EV_CONSOLE_MAIN_DEBUG_LEVELS_OPTARG_RESULT, \
    EV_CONSOLE_MAIN_DEBUG_LEVELS_OPTVAL_C}, \

#define EV_CONSOLE_MAIN_HELP_OPT "help"
#define EV_CONSOLE_MAIN_HELP_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_CONSOLE_MAIN_HELP_OPTARG_RESULT 0
#define EV_CONSOLE_MAIN_HELP_OPTARG EV_MAIN_HELP_OPTARG
#define EV_CONSOLE_MAIN_HELP_OPTUSE EV_MAIN_HELP_OPTUSE
#define EV_CONSOLE_MAIN_HELP_OPTVAL_S "?"
#define EV_CONSOLE_MAIN_HELP_OPTVAL_C '?'
#define EV_CONSOLE_MAIN_HELP_OPTION \
   {EV_CONSOLE_MAIN_HELP_OPT, \
    EV_CONSOLE_MAIN_HELP_OPTARG_REQUIRED, \
    EV_CONSOLE_MAIN_HELP_OPTARG_RESULT, \
    EV_CONSOLE_MAIN_HELP_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define EV_CONSOLE_MAIN_OPTIONS_CHARS \
    EV_CONSOLE_MAIN_DEBUG_LEVELS_OPTVAL_S \
    EV_CONSOLE_MAIN_HELP_OPTVAL_S \

#define EV_CONSOLE_MAIN_OPTIONS_OPTIONS \
    EV_CONSOLE_MAIN_DEBUG_LEVELS_OPTION \
    EV_CONSOLE_MAIN_HELP_OPTION \

namespace ev {
namespace console {

typedef xos::base::getopt::main_implement main_implement;
typedef xos::base::getopt::main main_extend;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implement, public main_extend {
public:
    typedef main_implement Implements;
    typedef main_extend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main() {
    }
    virtual ~main() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_debug_levels_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = on_logging_option
        (EV_MAIN_LOGGING_OPTVAL_C,
         optarg, optname, optind, argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_help_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = usage(argc, argv, env);
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
        case EV_CONSOLE_MAIN_DEBUG_LEVELS_OPTVAL_C:
            err = on_debug_levels_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case EV_CONSOLE_MAIN_HELP_OPTVAL_C:
            err = on_help_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* option_usage
    (const char*& optarg, const struct option* longopt) {
        const char* chars = "";
        switch(longopt->val) {
        case EV_CONSOLE_MAIN_DEBUG_LEVELS_OPTVAL_C:
            optarg = EV_CONSOLE_MAIN_DEBUG_LEVELS_OPTARG;
            chars = EV_CONSOLE_MAIN_DEBUG_LEVELS_OPTUSE;
            break;
        case EV_CONSOLE_MAIN_HELP_OPTVAL_C:
            optarg = EV_CONSOLE_MAIN_HELP_OPTARG;
            chars = EV_CONSOLE_MAIN_HELP_OPTUSE;
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* options(const struct option*& longopts) {
        int err = 0;
        static const char* chars = EV_CONSOLE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            EV_CONSOLE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace console
} // namespace ev 

#endif // _EV_CONSOLE_MAIN_HPP 
