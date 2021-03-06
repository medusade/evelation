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
#   File: ev.pri
#
# Author: $author$
#   Date: 10/30/2014
########################################################################
EV_PKG = ../../../../..
EV_BLD = ../..
EV_PRJ = $${EV_PKG}
EV_BIN = $${EV_BLD}/bin
EV_LIB = $${EV_BLD}/lib
EV_SRC = $${EV_PKG}/src

########################################################################
# talas
TALAS_PKG = $${EV_PKG}/../talas
TALAS_PRJ = $${TALAS_PKG}
TALAS_SRC = $${TALAS_PKG}/src

talas_INCLUDEPATH += \
$${TALAS_SRC} \

talas_DEFINES += \

########################################################################
# xos
XOS_PKG = $${EV_PKG}/../nadir
XOS_PRJ = $${XOS_PKG}
XOS_SRC = $${XOS_PKG}/src

xos_INCLUDEPATH += \
$${XOS_SRC} \

xos_DEFINES += \

########################################################################

ev_INCLUDEPATH += \
$${EV_SRC} \
$${talas_INCLUDEPATH} \
$${xos_INCLUDEPATH} \

ev_DEFINES += \
$${talas_DEFINES} \
$${xos_DEFINES} \

ev_HEADERS += \

ev_SOURCES += \

ev_LIBS += \
-L$${EV_LIB}/libevelation \
-levelation \
