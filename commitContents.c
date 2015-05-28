#include <stdio.h>
#include <string.h>
#include "gitViz.h"

void commitContents(char hash[], char contents[])
{
    FILE *commitHandle;
    char command[MAXLINE] = "git cat-file -p ";

    strcat(command, hash);

    commitHandle = popen(command, "r");
    fread(contents, MAXLINE, 1, commitHandle);
}


