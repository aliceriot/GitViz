#include <stdio.h>
#include "gitViz.h"

void getParent(char hash[], char parents[], char dir[])
{
    char contents[MAXLINE];

    commitContents(hash, contents);

    printf("%s\n", contents);

}
