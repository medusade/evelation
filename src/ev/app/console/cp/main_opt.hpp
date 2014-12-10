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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 11/8/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_APP_CONSOLE_CP_MAIN_OPT_HPP
#define _EV_APP_CONSOLE_CP_MAIN_OPT_HPP

#include "ev/app/console/main_opt.hpp"

#define EV_CONSOLE_CP_MAIN_TO_OPT "to"
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_RESULT 0
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_DOS_C 'd'
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_DOS_S "dos"
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_MAC_C 'm'
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_MAC_S "mac"
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_UNIX_C 'u'
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_UNIX_S "unix"
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_NATIVE_C 'n'
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_NATIVE_S "native"
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_SAME_C 's'
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_SAME_S "same"
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_SHA512_C '2'
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_SHA512_S "sha512"
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_SHA256_C '6'
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_SHA256_S "sha256"
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_SHA1_C '1'
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_SHA1_S "sha1"
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_MD5_C '5'
#define EV_CONSOLE_CP_MAIN_TO_OPTARG_MD5_S "md5"
#define EV_CONSOLE_CP_MAIN_TO_OPTARG "{(d)dos | (m)mac | (u)unix | (n)native | (s)same | (2)sha512 | (6)sha256 | (1)sha1 | (5)md5}"
#define EV_CONSOLE_CP_MAIN_TO_OPTUSE ""
#define EV_CONSOLE_CP_MAIN_TO_OPTVAL_S "2:"
#define EV_CONSOLE_CP_MAIN_TO_OPTVAL_C '2'
#define EV_CONSOLE_CP_MAIN_TO_OPTION \
   {EV_CONSOLE_CP_MAIN_TO_OPT, \
    EV_CONSOLE_CP_MAIN_TO_OPTARG_REQUIRED, \
    EV_CONSOLE_CP_MAIN_TO_OPTARG_RESULT, \
    EV_CONSOLE_CP_MAIN_TO_OPTVAL_C}, \

#define EV_CONSOLE_CP_MAIN_TEST_OPT "test"
#define EV_CONSOLE_CP_MAIN_TEST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_CONSOLE_CP_MAIN_TEST_OPTARG_RESULT 0
#define EV_CONSOLE_CP_MAIN_TEST_OPTARG ""
#define EV_CONSOLE_CP_MAIN_TEST_OPTUSE ""
#define EV_CONSOLE_CP_MAIN_TEST_OPTVAL_S "t"
#define EV_CONSOLE_CP_MAIN_TEST_OPTVAL_C 't'
#define EV_CONSOLE_CP_MAIN_TEST_OPTION \
   {EV_CONSOLE_CP_MAIN_TEST_OPT, \
    EV_CONSOLE_CP_MAIN_TEST_OPTARG_REQUIRED, \
    EV_CONSOLE_CP_MAIN_TEST_OPTARG_RESULT, \
    EV_CONSOLE_CP_MAIN_TEST_OPTVAL_C}, \

#define EV_CONSOLE_CP_MAIN_VERBOSE_OPT "verbose"
#define EV_CONSOLE_CP_MAIN_VERBOSE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_CONSOLE_CP_MAIN_VERBOSE_OPTARG_RESULT 0
#define EV_CONSOLE_CP_MAIN_VERBOSE_OPTARG ""
#define EV_CONSOLE_CP_MAIN_VERBOSE_OPTUSE ""
#define EV_CONSOLE_CP_MAIN_VERBOSE_OPTVAL_S "v"
#define EV_CONSOLE_CP_MAIN_VERBOSE_OPTVAL_C 'v'
#define EV_CONSOLE_CP_MAIN_VERBOSE_OPTION \
   {EV_CONSOLE_CP_MAIN_VERBOSE_OPT, \
    EV_CONSOLE_CP_MAIN_VERBOSE_OPTARG_REQUIRED, \
    EV_CONSOLE_CP_MAIN_VERBOSE_OPTARG_RESULT, \
    EV_CONSOLE_CP_MAIN_VERBOSE_OPTVAL_C}, \

#define EV_CONSOLE_CP_MAIN_WRITE_OPT "write"
#define EV_CONSOLE_CP_MAIN_WRITE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define EV_CONSOLE_CP_MAIN_WRITE_OPTARG_RESULT 0
#define EV_CONSOLE_CP_MAIN_WRITE_OPTARG_OVERWRITE_C 'o'
#define EV_CONSOLE_CP_MAIN_WRITE_OPTARG_OVERWRITE_S "overwrite"
#define EV_CONSOLE_CP_MAIN_WRITE_OPTARG_APPEND_C 'a'
#define EV_CONSOLE_CP_MAIN_WRITE_OPTARG_APPEND_S "append"
#define EV_CONSOLE_CP_MAIN_WRITE_OPTARG_CREATE_C 'c'
#define EV_CONSOLE_CP_MAIN_WRITE_OPTARG_CREATE_S "create"
#define EV_CONSOLE_CP_MAIN_WRITE_OPTARG "{(o)overwrite | (a)append | (c)create}"
#define EV_CONSOLE_CP_MAIN_WRITE_OPTUSE ""
#define EV_CONSOLE_CP_MAIN_WRITE_OPTVAL_S "w:"
#define EV_CONSOLE_CP_MAIN_WRITE_OPTVAL_C 'w'
#define EV_CONSOLE_CP_MAIN_WRITE_OPTION \
   {EV_CONSOLE_CP_MAIN_WRITE_OPT, \
    EV_CONSOLE_CP_MAIN_WRITE_OPTARG_REQUIRED, \
    EV_CONSOLE_CP_MAIN_WRITE_OPTARG_RESULT, \
    EV_CONSOLE_CP_MAIN_WRITE_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define EV_CONSOLE_CP_MAIN_OPTIONS_CHARS \
   EV_CONSOLE_CP_MAIN_TO_OPTVAL_S \
   EV_CONSOLE_CP_MAIN_TEST_OPTVAL_S \
   EV_CONSOLE_CP_MAIN_VERBOSE_OPTVAL_S \
   EV_CONSOLE_CP_MAIN_WRITE_OPTVAL_S \
   EV_CONSOLE_MAIN_OPTIONS_CHARS

#define EV_CONSOLE_CP_MAIN_OPTIONS_OPTIONS \
   EV_CONSOLE_CP_MAIN_TO_OPTION \
   EV_CONSOLE_CP_MAIN_TEST_OPTION \
   EV_CONSOLE_CP_MAIN_VERBOSE_OPTION \
   EV_CONSOLE_CP_MAIN_WRITE_OPTION \
   EV_CONSOLE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define EV_CONSOLE_CP_MAIN_SOURCE_ARG "source"
#define EV_CONSOLE_CP_MAIN_SOURCE_ARG_USE "source file"

#define EV_CONSOLE_CP_MAIN_TARGET_ARG "target"
#define EV_CONSOLE_CP_MAIN_TARGET_ARG_USE "target file"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define EV_CONSOLE_CP_MAIN_ARGS \
    EV_CONSOLE_CP_MAIN_SOURCE_ARG " " \
    EV_CONSOLE_CP_MAIN_TARGET_ARG " " \

#define EV_CONSOLE_CP_MAIN_ARGV \
    EV_CONSOLE_CP_MAIN_SOURCE_ARG " - " EV_CONSOLE_CP_MAIN_SOURCE_ARG_USE, \
    EV_CONSOLE_CP_MAIN_TARGET_ARG " - " EV_CONSOLE_CP_MAIN_TARGET_ARG_USE, \

namespace ev {
namespace app {
namespace console {
namespace cp {

} // namespace cp 
} // namespace console 
} // namespace app 
} // namespace ev 

#endif // _EV_APP_CONSOLE_CP_MAIN_OPT_HPP 
