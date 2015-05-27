#include <stdio.h>
#include "gitUtils.h"

#define MAXLINE 1000

main()
{
    char dir[MAXLINE];
    char commit[40];
    char head[40];
    char parents[MAXLINE];

    int headless;
    int lines = 0;

    getcwd(dir);
    
    headRef(head, dir);
    printf("%s", commit);
}
