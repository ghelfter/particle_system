#**************************************************
#*                  Galen Helfter
#*               ghelfter@gmail.com
#*                     Makefile
#**************************************************

SHELL = /bin/sh

# Compiler and linker flags
CC = gcc
#INC = -I/usr/local/cuda/include
#LIB = -L/usr/local/cuda/lib64
CFLAGS = -g -W -Wall -Wdeclaration-after-statement \
		 -pedantic -Wextra -O0 -std=c89 $(INC)
LDFLAGS = -g -W -Wall -Wdeclaration-after-statement \
		  -pedantic -Wextra -O0 -std=c89 $(LIB)
LIBS = -lm -lOpenCL

TARFILE = particle_system.tar.gz
ZIPFILE = particle_system.zip


CLEANFILES = *.o *.out core.* $(TARFILE) $(ZIPFILE)

# Object file list
OBJECTS =	main.o \
			load_cl.o

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
