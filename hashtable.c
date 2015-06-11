#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gitViz.h"

#define HASHSIZE 1000

static nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

nlist *lookup(char *s)
{
    nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

nlist *install(char *name, int p)
{
    nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free(np->index);
    if ((np->index = p) == NULL)
        return NULL;
    return np;
}
