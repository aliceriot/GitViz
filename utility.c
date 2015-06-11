#include <stdio.h>
#include <string.h>
#include "gitViz.h"

    /* UTILITY STUFF */

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


void commitContents(char hash[], char contents[])
{
    FILE *commitHandle;
    char command[MAXLINE] = "git cat-file -p ";

    strcat(command, hash);

    commitHandle = popen(command, "r");
    fread(contents, MAXLINE, 1, commitHandle);
    fclose(commitHandle);
}

void stringShift(char s[], int shift)
{
    int i;

    for (i = shift; i < strlen(s); i++)
        s[i - shift] = s[i];
    i -= shift;
    s[i] = '\0';
}

