#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "gitViz.h"

    /* TREE! */

static node *treeIndex[100];
static int p;

void treeInit(char *commits[], int numcommits)
{
    initialize();
    int i;
    for (i = 0; i < numcommits; i++)
        addNode(commits[i]);
    for (i = 0; i < numcommits; i++)
        addChildren(commits[i]);
}

int addNode(char hash[])
{
    node *temp;
    temp = malloc(sizeof(node));
    (*temp).commitHash = hash;
    (*temp).numchildren = 0;
    treeIndex[p] = temp;
    install(hash, p);
    p++;
    return 1;
}

void addChildren(char child[])
{
    node *childptr = getNode(child);
    node *parptr;
    char *parents[10];
    int numparents, i = 0;
    numparents = getParent(child, parents);
    for (i = 0; i < numparents; i++) {
        parptr = getNode(parents[i]);
        insertPtr(parptr, childptr);
    }
}

// fun with pointers!
void insertPtr(node *parent, node *child)
{
    int numchildren = parent->numchildren;
    parent->children[numchildren] = child;
    parent->numchildren++;
}

node *getNode(char commit[])
{
    nlist *loc;
    loc = lookup(commit);
    node *ptr = treeIndex[loc->index];
    return ptr;
}

// testing things
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

// utility functions
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
