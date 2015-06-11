CC=gcc
CFLAGS=-I -lm
DEPS = gitViz.h

out/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

vizmake: out/gitViz.o out/utility.o out/getParent.o out/printing.o out/graph.o out/getHashes.o out/hashtable.o
	$(CC) -lm -o gitViz.bin out/gitViz.o out/utility.o out/getParent.o out/printing.o out/graph.o out/getHashes.o out/hashtable.o
	
