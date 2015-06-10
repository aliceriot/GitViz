#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "gitViz.h"

/*     PRIVATE VARIABLES */

static node *treeIndex[100];
static node *p;

void initialize()
{
    p = treeIndex[0];
}

// I also need something like a hash table, to store a correspondence 
// between hashes and pointers (to node objects)

/*     FUNCTIONS */

int addNode(char hash[])
{
    node temp = {.commitHash = hash};
    p = &temp;
    p++;
    return 1;
    // add to lookup table
}

void printNodeHashes()
{
    node *c;
    c = treeIndex[0];
    while (c < p) {
        printf("%s\n", (*c).commitHash);
        c++;
    }
}

