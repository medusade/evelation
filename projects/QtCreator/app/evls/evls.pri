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
#   File: evls.pri
#
# Author: $author$
#   Date: 12/10/2014
########################################################################

evls_INCLUDEPATH += \
$${ev_INCLUDEPATH} \

evls_DEFINES += \
$${ev_DEFINES} \

evls_HEADERS += \
$${EV_SRC}/ev/app/console/ls/main.hpp \

#$${EV_SRC}/ev/base/base.hpp \
#$${EV_SRC}/ev/crypto/base.hpp \
#$${EV_SRC}/ev/fs/entry.hpp \
#$${EV_SRC}/ev/fs/path/match/read/events.hpp \
#$${EV_SRC}/ev/fs/path/match/reader.hpp \
#$${EV_SRC}/ev/fs/path/matcher.hpp \
#$${EV_SRC}/ev/fs/path/matchers.hpp \
#$${EV_SRC}/ev/fs/path/separate/events.hpp \
#$${EV_SRC}/ev/fs/path/separator.hpp \
#$${EV_SRC}/ev/fs/path/parts.hpp \
#$${EV_SRC}/ev/fs/path/directory/name.hpp \
#$${EV_SRC}/ev/fs/directory/path.hpp \
#$${EV_SRC}/ev/fs/directory/entry.hpp \

evls_SOURCES += \
$${EV_SRC}/ev/app/console/ls/main.cpp \
$${EV_SRC}/ev/console/main_main.cpp \

#$${EV_SRC}/ev/fs/path/matcher.cpp \
#$${EV_SRC}/ev/fs/path/match/reader.cpp \
#$${EV_SRC}/ev/fs/path/match/read/events.cpp \
#$${EV_SRC}/ev/fs/path/separator.cpp \
#$${EV_SRC}/ev/fs/path/parts.cpp \
#$${EV_SRC}/ev/fs/path/directory/name.cpp \

evls_LIBS += \
$${ev_LIBS} \

