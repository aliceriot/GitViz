#include <stdio.h>
#include <string.h>
#include "gitViz.h"

void headRef(char hash[], char dir[])
{
    FILE *head;
    FILE *branch;
    char headContents[MAXLINE];
    char dircopy[MAXLINE];
    char branchName[100];
    char branchLoc[MAXLINE];

    strcpy(dircopy, dir);

    // get the current branch
    strcat(dircopy,"/.git/HEAD");
    head = fopen(dircopy, "r");
    fgets(headContents, MAXLINE, head);
    fclose(head);

    // string processing
    sscanf(headContents, "ref: refs/heads/%s", branchName);

    // read branchName file, copy commit hash
    sprintf(branchLoc, "/.git/refs/heads/%s", branchName);
    strcpy(dircopy, dir);
    strcat(dircopy,branchLoc);
    branch = fopen(dircopy, "r");
    fgets(hash, MAXLINE, branch);
    fclose(branch);
}


