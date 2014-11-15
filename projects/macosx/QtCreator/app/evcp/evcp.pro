########################################################################
# Copyright (c) 1988-2014 $organization$
#
# This software is provided by the author and contributors ``as is'' 
# and any express or implied warranties, including, but not limited to, 
# the implied warranties of merchantability and fitness for a particular 
# purpose are disclaimed. In no event shall the author or contributors 
# be liable for any direct, indirect, incidental, special, exemplary, 
# or consequential damages (including, but not limited to, procurement 
# of substitute goods or services; loss of use, data, or profits; or 
# business interruption) however caused and on any theory of liability, 
# whether in contract, strict liability, or tort (including negligence 
# or otherwise) arising in any way out of the use of this software, 
# even if advised of the possibility of such damage.
#
#   File: evcp.pro
#
# Author: $author$
#   Date: 11/8/2014
########################################################################
include(../../../../QtCreator/ev.pri)
include(../../ev.pri)

TARGET = evcp

INCLUDEPATH += \
$${ev_INCLUDEPATH} \

DEFINES += \
$${ev_DEFINES} \

########################################################################
HEADERS += \
$${TALAS_SRC}/talas/crypto/hash/openssl/sha256.hpp \
$${TALAS_SRC}/talas/crypto/hash/sha256.hpp \
$${TALAS_SRC}/talas/crypto/hash/openssl/sha1.hpp \
$${TALAS_SRC}/talas/crypto/hash/sha1.hpp \
$${TALAS_SRC}/talas/crypto/hash/openssl/md5.hpp \
$${TALAS_SRC}/talas/crypto/hash/md5.hpp \
$${TALAS_SRC}/talas/crypto/hash/mac.hpp \
$${TALAS_SRC}/talas/crypto/hash/base.hpp \
$${TALAS_SRC}/talas/crypto/base.hpp \
$${TALAS_SRC}/talas/base/base.hpp \

SOURCES += \
$${TALAS_SRC}/talas/crypto/hash/openssl/sha256.cpp \
$${TALAS_SRC}/talas/crypto/hash/openssl/sha1.cpp \
$${TALAS_SRC}/talas/crypto/hash/openssl/md5.cpp \
$${TALAS_SRC}/talas/crypto/hash/mac.cpp \
$${TALAS_SRC}/talas/crypto/hash/base.cpp \

########################################################################
HEADERS += \
$${EV_SRC}/ev/os/macosx/fs/directory/path.hpp \
$${EV_SRC}/ev/os/macosx/fs/directory/entry.hpp \
$${EV_SRC}/ev/os/macosx/fs/entry.hpp \
$${EV_SRC}/ev/fs/directory/path.hpp \
$${EV_SRC}/ev/fs/directory/entry.hpp \
$${EV_SRC}/ev/os/unix/fs/directory/path.hpp \
$${EV_SRC}/ev/os/unix/fs/directory/entry.hpp \
$${EV_SRC}/ev/os/unix/fs/entry.hpp \
$${EV_SRC}/ev/fs/directory/path.hpp \
$${EV_SRC}/ev/fs/directory/entry.hpp \
$${EV_SRC}/ev/fs/entry.hpp \
$${EV_SRC}/ev/fs/path/separate/events.hpp \
$${EV_SRC}/ev/fs/path/separator.hpp \
$${EV_SRC}/ev/fs/path/parts.hpp \
$${EV_SRC}/ev/crypto/base.hpp \
$${EV_SRC}/ev/base/base.hpp \
$${EV_SRC}/ev/app/console/cp/main.hpp \
$${EV_SRC}/ev/console/main.hpp \
$${EV_SRC}/ev/console/main_main.hpp \

SOURCES += \
$${EV_SRC}/ev/os/unix/fs/directory/path.hpp \
$${EV_SRC}/ev/os/unix/fs/directory/entry.hpp \
$${EV_SRC}/ev/fs/path/separate/events.cpp \
$${EV_SRC}/ev/fs/path/separator.cpp \
$${EV_SRC}/ev/fs/path/parts.cpp \
$${EV_SRC}/ev/app/console/cp/main.cpp \
$${EV_SRC}/ev/console/main_main.cpp \

LIBS += \
$${ev_LIBS} \
-lpthread \
-ldl \


        

