BASEDIR	=	.

CC = g++
CXX = g++
CPPFLAGS = -Wall -O2 -I ${BASEDIR}/include
LDLIBS = -lGLU -lGL -lglut -llm

all:	main

main:	main.cpp ${BASEDIR}/libsrc/*.cpp

clean:
	rm -rf main
