#include <stdio.h>
#include "gitViz.h"

void getParent(char hash[], char parents[], char dir[])
{
    char contents[MAXLINE];
    char parentLine[MAXLINE];
    char scratch[MAXLINE];

    commitContents(hash, contents);

    //sscanf(commitContents, "%s", scratch);

    printf("%s\n", commitContents);
    printf("%s\n", scratch);

    

}
