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
    treeInit(commits, numcommits);

    printNodeHashes();

    deinitialize(numcommits);
}


