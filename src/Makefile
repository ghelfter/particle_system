#**************************************************
#*                  Galen Helfter
#*               ghelfter@gmail.com
#*                     Makefile
#**************************************************

SHELL = /bin/sh

# Compiler and linker flags
CC = gcc
INC = -I/usr/lib/x86_64-linux-gnu
LIB = -L/usr/lib/x86_64-linux-gnu
CFLAGS = -g -W -Wall -Wdeclaration-after-statement \
		 -pedantic -Wextra -O0 -std=c89 $(INC)
LDFLAGS = -g -W -Wall -Wdeclaration-after-statement \
		  -pedantic -Wextra -O0 -std=c89 $(LIB)
LIBS = -lm -lOpenCL -lGL -lGLEW -lglfw

TARFILE = particle_system.tar.gz
ZIPFILE = particle_system.zip


CLEANFILES = *.o *.out core.* $(TARFILE) $(ZIPFILE)

# Object file list
OBJECTS =	main.o \
			init_gl.o \
			init_cl.o \
			interop.o \
			load_shader.o

# Programs

PROGS = run

all:		$(PROGS)

run:		$(OBJECTS) $(LIBS)
			$(CC) $(LDFLAGS) -o $@ $(OBJECTS) $(LIBS)


.PHONY: clean tar zip
clean:
		rm -f $(PROGS) $(CLEANFILES)
tar:
		rm -f $(TARFILE)
		tar -czvf $(TARFILE) ./*
zip:
		rm -f $(ZIPFILE)
		zip $(ZIPFILE) ./*
