#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

// get the commit referenced in HEAD (usually master)
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
    strcat(dir,"/.git/HEAD");
    head = fopen(dir, "r");
    fgets(headContents, MAXLINE, head);
    fclose(head);

    // string processing
    char crap[100];
    sscanf(headContents, "ref: refs/heads/%s", branchName);

    // read branchName file, copy commit hash
    sprintf(branchLoc, "/.git/refs/heads/%s", branchName);
    strcat(dircopy,branchLoc);
    branch = fopen(dircopy, "r");
    fgets(hash, MAXLINE, branch);

}

/* // parents of a commit, returned with linebreaks in between */
/* void getParent(char hash[], char parents[]) */
/* { */
/* } */

/* // is git currently headless? */
/* int headless(char hash[]) */
/* { */
/* } */

/* int printCommit(char hash[]) */
/* { */
/*     // do some stuff */
/*     if (parents) */
/*         return 1; */
/*     else */
/*         return 0; */
/* } */


