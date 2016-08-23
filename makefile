###########################################################################
 ## Program Filename: makefile
 ## Author: Sara Hashem
 ## Date: 07/06/16
 ##########################################################################

# Standard variables
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -g


# Source files
SRC1 = MaxSubarrayEnumeration.cpp
SRC2 = MaxSubarrayRec.cpp
SRC3 = MaxSubarrayLinear.cpp
SRC4= testIOMain.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4}


# Header files
HEADER1 = MaxSubarrayEnumeration.cpp
HEADER2 = MaxSubarrayRec.cpp
HEADER3 = MaxSubarrayLinear.cpp
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3}


# Object files
OBJ1 = enum.o
OBJ2 = rec.o
OBJ3 = linear.o
OBJS = ${OBJ1} ${OBJ2} ${OBJ3}


# Executable
PROG = mss


all: ${OBJS} ${SRCS}
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG}


enum.o: ${HEADER1} ${SRC1}
	${CXX} ${CXXFLAGS} ${SRC1} -c


rec.o: ${HEADER2} ${SRC2}
	${CXX} ${CXXFLAGS} ${SRC2} -c


linear.o: ${HEADER3} ${SRC3}
	${CXX} ${CXXFLAGS} ${SRC3} -c


clean:
	rm -f ${PROG} *.o
