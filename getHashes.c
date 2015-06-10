#include <stdio.h>
#include <string.h>
#include "gitViz.h"

int getHashes(char buffer[], char *hashes[])
{
    // read into buffer
    FILE *hash_handle;
    char command[] = "git log --reverse --format=%H";
    char readbuffer[42];
    char *p = buffer;
    int numcommits = 0;

    hash_handle = popen(command, "r");

    while (fgets(readbuffer, 42, hash_handle)) {
        readbuffer[40] = '\0';
        strcpy(p, readbuffer);
        hashes[numcommits++] = p;
        p += 42;
    }
    fclose(hash_handle);

    return numcommits;
}

