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
    install(hash, p);
    p++;
    return 1;
}

void printHash(int index)
{
    printf("%s\n", (*treeIndex[index]).commitHash);
}

void printNodeHashes()
{
    int i = 0;
    while (i < p) {
        printf("%s\n", (*treeIndex[i]).commitHash);
        i++;
    }
}

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
