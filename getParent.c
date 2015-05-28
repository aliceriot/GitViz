#include <stdio.h>
#include "gitViz.h"

void getParent(char hash[], char parents[], char dir[])
{
    char contents[MAXLINE];
    char scratch[MAXLINE];

    commitContents(hash, contents);

    


    printf("%s\n", contents);

    

}
