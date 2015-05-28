#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "gitViz.h"

#define MAXLINE 1000

void main()
{
    char dir[MAXLINE];
    char commit[40];
    char head[40];
    char parents[MAXLINE];

    int headless;
    int lines = 0;

    getcwd(dir, MAXLINE);
    
    // get the last commit in current branch
    headRef(head, dir);
    printf("%s", head);
    
    // find the parent of this commit!
    getParent(head, parents, dir);
}
