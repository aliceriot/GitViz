#include <stdio.h>
#include <string.h>
#include "gitViz.h"

// this takes a hash and returns the filepath to the file in 
// the git objects directory that contains the contents of that
// hash
void hashLocation(char hash[], char location[], char dir[])
{
    char scratchBuffer[MAXLINE];

    strcpy(location, dir);
    strcat(location, "/.git/objects/");
    sscanf(hash, "%2s%*S", scratchBuffer);
    strcat(location,scratchBuffer);
    strcat(location,"/");
    sscanf(hash, "%*2s%s", scratchBuffer);
    strcat(location,scratchBuffer);
}


