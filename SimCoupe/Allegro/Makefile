# SimCoupe - A SAM Coupe emulator
#
# Allegro Makefile
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

TARGET=simcoupe
CC=gcc
CXX=gxx

ALLEGRO=.
BASE=../Base
EXTERN=../Extern

USE_ZLIB=1
USE_SAASOUND=1

.SUFFIXES: .cpp .c

CFLAGS=-O3 -pedantic -fomit-frame-pointer -funroll-loops -finline-functions -I${ALLEGRO} -I${BASE} -I${EXTERN}
#CFLAGS=-O2 -I${ALLEGRO} -I${BASE} -I${EXTERN}
CXXFLAGS=${CFLAGS} -Wall
LIBS=-L. -L/usr/local/lib -lm -lalleg

BASE_SRC=${BASE}/Action.cpp ${BASE}/ATA.cpp ${BASE}/Atom.cpp \
 ${BASE}/BlueAlpha.cpp ${BASE}/CDisk.cpp ${BASE}/CDrive.cpp ${BASE}/Clock.cpp \
 ${BASE}/CPU.cpp ${BASE}/CScreen.cpp ${BASE}/CStream.cpp ${BASE}/Debug.cpp \
 ${BASE}/Disassem.cpp ${BASE}/Expr.cpp ${BASE}/Font.cpp ${BASE}/Frame.cpp \
 ${BASE}/GUI.cpp ${BASE}/GUIDlg.cpp ${BASE}/GUIIcons.cpp ${BASE}/HardDisk.cpp \
 ${BASE}/IO.cpp ${BASE}/Main.cpp ${BASE}/Memory.cpp ${BASE}/Mouse.cpp \
 ${BASE}/Options.cpp ${BASE}/Parallel.cpp ${BASE}/PNG.cpp ${BASE}/SDIDE.cpp \
 ${BASE}/Util.cpp ${BASE}/YATBus.cpp \
 ${EXTERN}/SAASound.cpp

ALLEGRO_SRC= ${ALLEGRO}/Display.cpp ${ALLEGRO}/Floppy.cpp \
 ${ALLEGRO}/IDEDisk.cpp ${ALLEGRO}/Input.cpp ${ALLEGRO}/MIDI.cpp \
 ${ALLEGRO}/OSD.cpp ${ALLEGRO}/Sound.cpp ${ALLEGRO}/UI.cpp \
 ${ALLEGRO}/Video.cpp

ifeq (${USE_ZLIB},1)
CFLAGS += -DUSE_ZLIB
LIBS += -lz
endif

ifeq (${USE_SAASOUND},1)
CFLAGS += -DUSE_SAASOUND
LIBS += -lSAASound
endif

BASE_OBJS=$(BASE_SRC:%.cpp=%.o) ${EXTERN}/unzip.o ${EXTERN}/ioapi.o
ALLEGRO_OBJS=$(ALLEGRO_SRC:%.cpp=%.o)

all:	${TARGET}

${TARGET}:	${BASE_OBJS} ${ALLEGRO_OBJS} Makefile
	${CXX} -o ${TARGET} ${CXXFLAGS} ${BASE_OBJS} ${ALLEGRO_OBJS} ${LIBS}

.cpp.o:
	${CXX} -o $@ -c $< ${CXXFLAGS}

.c.o:
	${CC} -o $@ -c $< ${CFLAGS}

clean:
	rm -f ${TARGET} ${TARGET}.exe ${BASE}/*.o ${ALLEGRO}/*.o ${EXTERN}/*.o
