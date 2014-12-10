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
#   File: evls.pro
#
# Author: $author$
#   Date: 10/30/2014
########################################################################
include(../../../../QtCreator/ev.pri)
include(../../ev.pri)
include(../../../../QtCreator/app/evls/evls.pri)

TARGET = evls

INCLUDEPATH += \
$${evls_INCLUDEPATH} \

DEFINES += \
$${evls_DEFINES} \

########################################################################
HEADERS += \
$${evls_HEADERS} \
$${EV_SRC}/ev/os/macosx/fs/directory/path.hpp \
$${EV_SRC}/ev/os/macosx/fs/directory/entry.hpp \
$${EV_SRC}/ev/os/macosx/fs/entry.hpp \
$${EV_SRC}/ev/os/unix/fs/directory/path.hpp \
$${EV_SRC}/ev/os/unix/fs/directory/entry.hpp \
$${EV_SRC}/ev/os/unix/fs/entry.hpp \

SOURCES += \
$${evls_SOURCES} \
$${EV_SRC}/ev/os/macosx/fs/directory/path.cpp \
$${EV_SRC}/ev/os/macosx/fs/directory/entry.cpp \

LIBS += \
$${evls_LIBS} \

