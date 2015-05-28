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
}

// takes a hash, output string, and working dir
// maybe I don't actually need this
void commitLocation(char hash[], char location[], char dir[])
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

// get the text in a commit object
void commitContents(char hash[], char contents[])
{
    FILE *commitHandle;
    char command[MAXLINE] = "git cat-file -p ";

    strcat(command, hash);

    commitHandle = popen(command, "r");
    fread(contents, MAXLINE, 1, commitHandle);
}

// parents of a commit, returned with linebreaks in between
void getParent(char hash[], char parents[], char dir[])
{
    char contents[MAXLINE];

    commitContents(hash, contents);

    printf("%s\n", contents);

}


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


