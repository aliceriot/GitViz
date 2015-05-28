CC=gcc
CFLAGS=-I -lm
DEPS = gitUtils.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hexmake: gitViz.o
	$(CC) -lm -o gitViz.bin gitViz.o
