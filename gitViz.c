#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "gitViz.h"


void main()
{
    char buffer[10000];
    char *commits[100];
    int numcommits, i;

    numcommits = getHashes(buffer, commits);

    initialize();
    for (i = 0; i < numcommits; i++)
        addNode(commits[i]);

    printNodeHashes();


    nlist *hashLoc;
    hashLoc = lookup("4754c5db6989aba5415541afba288554f9715b2a");
    int hashindex;
    hashindex = hashLoc->index;
    printf("%d\n", hashindex);
    printHash(hashindex);

    addChildren("4754c5db6989aba5415541afba288554f9715b2a");

    // make sure this is at the end! lol
    deinitialize(numcommits);
}


