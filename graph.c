#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "gitViz.h"

/*     PRIVATE VARIABLES */

static node *treeIndex[100];
static int p;

int addNode(char hash[])
{
    node *temp;
    temp = malloc(sizeof(node));
    (*temp).commitHash = hash;
    treeIndex[p] = temp;
    p++;
    return 1;
    // add to lookup table
}

void printNodeHashes()
{
    int i = 0;
    while (i < p) {
        printf("%s\n", (*treeIndex[i]).commitHash);
        i++;
    }
}






// irritating helper functions
void initialize()
{
    p = 0;
}
void deinitialize(int numcommits)
{
    int i;
    for (i = 0; i < numcommits; i++)
        free(treeIndex[i]);
}
