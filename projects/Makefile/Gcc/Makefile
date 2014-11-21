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
#   File: Makefile
#
# Author: $author$
#   Date: 11/5/2014
#
# Common Gcc Makefile for evelation
########################################################################
EV_PKG = ${PKG}
EV_SRC = ${EV_PKG}/src

########################################################################
# xos
XOS_PKG = ${EV_PKG}/../nadir
XOS_SRC = ${XOS_PKG}/src
XOS_BLD = ${XOS_PKG}/${BLD}/${BUILD_TYPE}
XOS_LIB = ${XOS_BLD}/lib
XOS_BIN = ${XOS_BLD}/bin

########################################################################
# talas
TALAS_PKG = ${EV_PKG}/../talas
TALAS_SRC = ${TALAS_PKG}/src
TALAS_BLD = ${TALAS_PKG}/${BLD}/${BUILD_TYPE}
TALAS_LIB = ${TALAS_BLD}/lib
TALAS_BIN = ${TALAS_BLD}/bin

########################################################################
# ev
ev_USRDEFINES += \

ev_USRINCLUDES += \
-I${EV_SRC} \
-I${TALAS_SRC} \
-I${XOS_SRC} \

ev_USRLIBDIRS += \
-L${TALAS_LIB} \
-L${XOS_LIB} \

ev_USRLIBS += \
-lxosnadir \
