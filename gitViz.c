#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "gitViz.h"


void main()
{
    char buffer[20000];
    char *commits[1000];
    int numcommits, i;

    numcommits = getHashes(buffer, commits);
    treeInit(commits, numcommits);

    printGraph(commits, numcommits);
    
    // testcolumns(commits);


    deinitialize(numcommits);
}


