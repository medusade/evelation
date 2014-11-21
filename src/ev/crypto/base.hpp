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
///   File: base.hpp
///
/// Author: $author$
///   Date: 11/11/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_CRYPTO_BASE_HPP
#define _EV_CRYPTO_BASE_HPP

#include "talas/crypto/hash/implementation/sha256.hpp"
#include "talas/crypto/hash/implementation/sha1.hpp"
#include "talas/crypto/hash/implementation/md5.hpp"

namespace ev {
namespace crypto {

namespace hash {

typedef talas::crypto::hash::base base;
typedef talas::crypto::hash::implementation::md5 md5;
typedef talas::crypto::hash::implementation::sha1 sha1;
typedef talas::crypto::hash::implementation::sha256 sha256;

} // namespace hash

} // namespace crypto
} // namespace ev

#endif // _EV_CRYPTO_BASE_HPP 
