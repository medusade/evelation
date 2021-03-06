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
///   File: path.hpp
///
/// Author: $author$
///   Date: 10/31/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_FS_DIRECTORY_PATH_HPP
#define _EV_FS_DIRECTORY_PATH_HPP

#include "ev/fs/directory/entry.hpp"

namespace ev {
namespace fs {
namespace directory {

typedef entry path_entry;
typedef openert<entry_implements> path_implements;
///////////////////////////////////////////////////////////////////////
///  Class: patht
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TString = string_t, class TEntry = path_entry,
 class TImplements = path_implements>

class _EXPORT_CLASS patht: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TEntry entry_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open(const char_t* name) {
        return false;
    }
    virtual bool close() {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual entry_t* get_first_entry() {
        return 0;
    }
    virtual entry_t* get_next_entry() {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef patht<> path;

} // namespace directory 
} // namespace fs 
} // namespace ev 

#endif // _EV_FS_DIRECTORY_PATH_HPP 
