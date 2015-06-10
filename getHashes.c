#include <stdio.h>
#include "gitViz.h"


// git log --reverse --format=%H
// this gets us all the hashes, in reverse order!

void getHashes()
{
    FILE *hash_handle;
    char command[] = "git log --reverse --format=%H";
    char hashes[MAXLINE];

    hash_handle = popen(command, "r");
    fread(hashes, MAXLINE, 1, hash_handle);
    fclose(hash_handle);

    printf("%s\n", hashes);
}


void main()
{
    getHashes();
}
