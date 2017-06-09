#
#	Compiler
#
COMPILER		=	g++
LINKER			=	g++
COMPILER_FLAGS		=	-Wall -c -O2 -std=c++11 -fpic -Iinclude -o
LINKER_FLAGS		=	-shared
LINKER_DEPENDENCIES	=	-lphpcpp

UBUNTU_MAJOR  := $(shell /usr/bin/lsb_release -r -s | cut -f1 -d.)
OVER_SIXTEEN  := $(shell echo "${UBUNTU_MAJOR} >= 16" | bc)
OVER_FOURTEEN := $(shell echo "${UBUNTU_MAJOR} >= 14" | bc)

NAME			=	cpphalcon
EXTENSION 		=	${NAME}.so
EXTENSION_DIR	=	$(shell php-config --extension-dir)
INI 			=	${NAME}.ini

ifeq (${OVER_SIXTEEN}, 1)
    INI_DIR     =   /etc/php/7.0/mods-available/
else ifeq (${OVER_FOURTEEN}, 1)
    INI_DIR     =   /etc/php5/mods-available/
else
    INI_DIR     =   /etc/php5/conf.d/
endif

RM			=	rm -f
CP			=	cp -f
MKDIR		=	mkdir -p

HEADERS			=	$(wildcard include/*.h) $(wildcard include/*/*.h)
SOURCES			=	$(wildcard *.cpp) $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
OBJECTS			=	$(SOURCES:%.cpp=%.o)


#
#	From here the build instructions start
#

all: ${OBJECTS} ${EXTENSION}

${EXTENSION}: ${OBJECTS}
	${LINKER} ${LINKER_FLAGS} -o $@ ${OBJECTS} ${LINKER_DEPENDENCIES}

${OBJECTS}: ${SOURCES} ${HEADERS}
	${COMPILER} ${COMPILER_FLAGS} $@ ${@:%.o=%.cpp}

install: ${EXTENSION}
	${CP} ${EXTENSION} ${EXTENSION_DIR}
	${CP} ${INI} ${INI_DIR}
				
clean:
	${RM} *.obj *~* ${EXTENSION} ${OBJECTS}
