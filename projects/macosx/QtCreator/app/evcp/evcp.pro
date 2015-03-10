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
include(../../../../QtCreator/app/evcp/evcp.pri)

TARGET = evcp

INCLUDEPATH += \
$${evcp_INCLUDEPATH} \

DEFINES += \
$${evcp_DEFINES} \

########################################################################
HEADERS += \
$${evcp_HEADERS} \

#$${EV_SRC}/ev/os/macosx/fs/directory/path.hpp \
#$${EV_SRC}/ev/os/macosx/fs/directory/entry.hpp \
#$${EV_SRC}/ev/os/macosx/fs/entry.hpp \
#$${EV_SRC}/ev/os/unix/fs/directory/path.hpp \
#$${EV_SRC}/ev/os/unix/fs/directory/entry.hpp \
#$${EV_SRC}/ev/os/unix/fs/entry.hpp \

SOURCES += \
$${evcp_SOURCES} \

#$${EV_SRC}/ev/os/macosx/fs/directory/path.cpp \
#$${EV_SRC}/ev/os/macosx/fs/directory/entry.cpp \

LIBS += \
$${evcp_LIBS} \

