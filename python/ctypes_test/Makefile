#
#   Makefile
#
  

CC  = gcc
CFLAGS = -c
DEBUG = -g -Wall
#FLAGS = -I ./include

CSOFLAGS = -fPIC -shared



libfoo.so: test.c test_a.c
	$(CC) $^ $(CSOFLAGS) -o $@


.PHONY:clean cleanall all

all:  libfoo.so

clean:
	@rm *.o

cleanall:
	@rm *.o *.so
