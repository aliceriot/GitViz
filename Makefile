CC=gcc
CFLAGS=-I -lm
DEPS = gitViz.h

out/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hexmake: out/gitViz.o out/headref.o out/commitContents.o out/commitLocation.o out/getParent.o
	$(CC) -lm -o gitViz.bin out/gitViz.o out/headref.o out/commitContents.o out/commitLocation.o out/getParent.o
	
