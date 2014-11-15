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
///   Date: 10/31/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_APP_CONSOLE_LS_MAIN_OPT_HPP
#define _EV_APP_CONSOLE_LS_MAIN_OPT_HPP

#include "ev/app/console/main_opt.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPT "before-directory"
#define EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPTVAL_S "B:"
#define EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPTVAL_C 'B'
#define EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPT, \
    EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPT "after-directory"
#define EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPTVAL_S "A:"
#define EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPTVAL_C 'A'
#define EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPT, \
    EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPT "between-directory"
#define EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPTVAL_S "W:"
#define EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPTVAL_C 'W'
#define EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPT, \
    EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_BEFORE_OPT "output-before"
#define EV_APP_CONSOLE_LS_MAIN_BEFORE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define EV_APP_CONSOLE_LS_MAIN_BEFORE_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_BEFORE_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_BEFORE_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_BEFORE_OPTVAL_S "b:"
#define EV_APP_CONSOLE_LS_MAIN_BEFORE_OPTVAL_C 'b'
#define EV_APP_CONSOLE_LS_MAIN_BEFORE_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_BEFORE_OPT, \
    EV_APP_CONSOLE_LS_MAIN_BEFORE_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_BEFORE_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_BEFORE_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_AFTER_OPT "output-after"
#define EV_APP_CONSOLE_LS_MAIN_AFTER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define EV_APP_CONSOLE_LS_MAIN_AFTER_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_AFTER_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_AFTER_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_AFTER_OPTVAL_S "a:"
#define EV_APP_CONSOLE_LS_MAIN_AFTER_OPTVAL_C 'a'
#define EV_APP_CONSOLE_LS_MAIN_AFTER_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_AFTER_OPT, \
    EV_APP_CONSOLE_LS_MAIN_AFTER_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_AFTER_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_AFTER_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPT "output-between"
#define EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPTVAL_S "w:"
#define EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPTVAL_C 'w'
#define EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPT, \
    EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_NAME_OPT "output-name"
#define EV_APP_CONSOLE_LS_MAIN_NAME_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_APP_CONSOLE_LS_MAIN_NAME_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_NAME_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_NAME_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_NAME_OPTVAL_S "n"
#define EV_APP_CONSOLE_LS_MAIN_NAME_OPTVAL_C 'n'
#define EV_APP_CONSOLE_LS_MAIN_NAME_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_NAME_OPT, \
    EV_APP_CONSOLE_LS_MAIN_NAME_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_NAME_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_NAME_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_SOURCE_OPT "output-source"
#define EV_APP_CONSOLE_LS_MAIN_SOURCE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_APP_CONSOLE_LS_MAIN_SOURCE_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_SOURCE_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_SOURCE_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_SOURCE_OPTVAL_S "s"
#define EV_APP_CONSOLE_LS_MAIN_SOURCE_OPTVAL_C 's'
#define EV_APP_CONSOLE_LS_MAIN_SOURCE_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_SOURCE_OPT, \
    EV_APP_CONSOLE_LS_MAIN_SOURCE_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_SOURCE_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_SOURCE_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_TARGET_OPT "output-target"
#define EV_APP_CONSOLE_LS_MAIN_TARGET_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_APP_CONSOLE_LS_MAIN_TARGET_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_TARGET_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_TARGET_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_TARGET_OPTVAL_S "t"
#define EV_APP_CONSOLE_LS_MAIN_TARGET_OPTVAL_C 't'
#define EV_APP_CONSOLE_LS_MAIN_TARGET_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_TARGET_OPT, \
    EV_APP_CONSOLE_LS_MAIN_TARGET_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_TARGET_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_TARGET_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_REVERSE_OPT "output-reverse"
#define EV_APP_CONSOLE_LS_MAIN_REVERSE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_APP_CONSOLE_LS_MAIN_REVERSE_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_REVERSE_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_REVERSE_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_REVERSE_OPTVAL_S "v"
#define EV_APP_CONSOLE_LS_MAIN_REVERSE_OPTVAL_C 'v'
#define EV_APP_CONSOLE_LS_MAIN_REVERSE_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_REVERSE_OPT, \
    EV_APP_CONSOLE_LS_MAIN_REVERSE_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_REVERSE_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_REVERSE_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPT "output-directory"
#define EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPTVAL_S "y"
#define EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPTVAL_C 'y'
#define EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPT, \
    EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPT "directory-only"
#define EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPTVAL_S "Y"
#define EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPTVAL_C 'Y'
#define EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPT, \
    EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPT "recursive"
#define EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTVAL_S "r"
#define EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTVAL_C 'r'
#define EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPT, \
    EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPT "reflective"
#define EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTVAL_S "f"
#define EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTVAL_C 'f'
#define EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPT, \
    EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPT "match-file"
#define EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPTVAL_S "M:"
#define EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPTVAL_C 'M'
#define EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPT, \
    EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPT "skip-file"
#define EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPTVAL_S "K:"
#define EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPTVAL_C 'K'
#define EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPT, \
    EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_MATCH_OPT "match"
#define EV_APP_CONSOLE_LS_MAIN_MATCH_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define EV_APP_CONSOLE_LS_MAIN_MATCH_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_MATCH_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_MATCH_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_MATCH_OPTVAL_S "m:"
#define EV_APP_CONSOLE_LS_MAIN_MATCH_OPTVAL_C 'm'
#define EV_APP_CONSOLE_LS_MAIN_MATCH_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_MATCH_OPT, \
    EV_APP_CONSOLE_LS_MAIN_MATCH_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_MATCH_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_MATCH_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_SKIP_OPT "skip"
#define EV_APP_CONSOLE_LS_MAIN_SKIP_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define EV_APP_CONSOLE_LS_MAIN_SKIP_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_SKIP_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_SKIP_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_SKIP_OPTVAL_S "k:"
#define EV_APP_CONSOLE_LS_MAIN_SKIP_OPTVAL_C 'k'
#define EV_APP_CONSOLE_LS_MAIN_SKIP_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_SKIP_OPT, \
    EV_APP_CONSOLE_LS_MAIN_SKIP_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_SKIP_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_SKIP_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPT "match-case"
#define EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPTVAL_S "c"
#define EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPTVAL_C 'c'
#define EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPT, \
    EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPT "ignore-case"
#define EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPTVAL_S "i"
#define EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPTVAL_C 'i'
#define EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPT, \
    EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPT "compare-files"
#define EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPTVAL_S "p"
#define EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPTVAL_C 'p'
#define EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPT, \
    EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPT "existing-files"
#define EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPTVAL_S "x"
#define EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPTVAL_C 'x'
#define EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPT, \
    EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPT "missing-files"
#define EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPTVAL_S "g"
#define EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPTVAL_C 'g'
#define EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPT, \
    EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPT "older-files"
#define EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPTVAL_S "o"
#define EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPTVAL_C 'o'
#define EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPT, \
    EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPT "all-files"
#define EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPTVAL_S "l"
#define EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPTVAL_C 'l'
#define EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPT, \
    EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPT "exclude-file-links"
#define EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPTVAL_S "u"
#define EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPTVAL_C 'u'
#define EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPT, \
    EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPT "db"
#define EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPTVAL_S "d:"
#define EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPTVAL_C 'd'
#define EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPT, \
    EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPTVAL_C}, \

#define EV_APP_CONSOLE_LS_MAIN_HELP_OPT "help"
#define EV_APP_CONSOLE_LS_MAIN_HELP_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define EV_APP_CONSOLE_LS_MAIN_HELP_OPTARG_RESULT 0
#define EV_APP_CONSOLE_LS_MAIN_HELP_OPTARG ""
#define EV_APP_CONSOLE_LS_MAIN_HELP_OPTUSE ""
#define EV_APP_CONSOLE_LS_MAIN_HELP_OPTVAL_S "h"
#define EV_APP_CONSOLE_LS_MAIN_HELP_OPTVAL_C 'h'
#define EV_APP_CONSOLE_LS_MAIN_HELP_OPTION \
   {EV_APP_CONSOLE_LS_MAIN_HELP_OPT, \
    EV_APP_CONSOLE_LS_MAIN_HELP_OPTARG_REQUIRED, \
    EV_APP_CONSOLE_LS_MAIN_HELP_OPTARG_RESULT, \
    EV_APP_CONSOLE_LS_MAIN_HELP_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define EV_APP_CONSOLE_LS_MAIN_OPTIONS_CHARS \
   EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_BEFORE_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_AFTER_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_NAME_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_SOURCE_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_TARGET_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_REVERSE_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_MATCH_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_SKIP_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPTVAL_S \
   EV_APP_CONSOLE_LS_MAIN_HELP_OPTVAL_S \

//XOS_MAIN_OPTIONS_CHARS

#define EV_APP_CONSOLE_LS_MAIN_OPTIONS_OPTIONS \
   EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPTION \
   EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPTION \
   EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPTION \
   EV_APP_CONSOLE_LS_MAIN_BEFORE_OPTION \
   EV_APP_CONSOLE_LS_MAIN_AFTER_OPTION \
   EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPTION \
   EV_APP_CONSOLE_LS_MAIN_NAME_OPTION \
   EV_APP_CONSOLE_LS_MAIN_SOURCE_OPTION \
   EV_APP_CONSOLE_LS_MAIN_TARGET_OPTION \
   EV_APP_CONSOLE_LS_MAIN_REVERSE_OPTION \
   EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPTION \
   EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPTION \
   EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTION \
   EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTION \
   EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPTION \
   EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPTION \
   EV_APP_CONSOLE_LS_MAIN_MATCH_OPTION \
   EV_APP_CONSOLE_LS_MAIN_SKIP_OPTION \
   EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPTION \
   EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPTION \
   EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPTION \
   EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPTION \
   EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPTION \
   EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPTION \
   EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPTION \
   EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPTION \
   EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPTION \
   EV_APP_CONSOLE_LS_MAIN_HELP_OPTION \

//XOS_MAIN_OPTIONS_OPTIONS

namespace ev {
namespace app {
namespace console {
namespace ls {

} // namespace ls 
} // namespace console 
} // namespace app 
} // namespace ev 

#endif // _EV_APP_CONSOLE_LS_MAIN_OPT_HPP 
