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
}


