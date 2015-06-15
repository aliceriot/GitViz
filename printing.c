#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "gitViz.h"

char printBuffer[10000];
node *columns[10];




void printGraph(char *commits[], int numcommits)
{
    //printInitialize();
    node *root = getNode(commits[0]);
    node *commit = getNode(commits[2]);
    memset(columns, 0, sizeof(node *));
    
    printf("problem!");
    
    // lineFormat(rootHash);
    columns[0] = root;
    columns[1] = commit;

    printf("\nroot: %s\n", root->commitHash);

    columnDelete(0);

    int col = findColumn(commit->commitHash);

    printf("%d\n", col);

    columnInsert(getNode(commits[2]), 4);

    col = findColumn(commits[2]);

    printf("%d\n", col);

    
}
        
    /* TO IMPLEMENT */

// return the rightmost column for a commit
int findColumn(char *hash)
{
    int i;
    node *ptr = getNode(hash);
    for (i = 9; i >= 0; i--) {
        if (ptr == columns[i])
            return i;
    }
    return -1;
}

void columnDelete(int index)
{
    int i;
    for (i = index; i < 8; i++)
        columns[i] = columns[i+1];
    columns[9] = 0;
}

// insert a number of columns for a commit at a location
void columnInsert(node *commit, int index)
{
    node *temp;
    if (index == 9)
        columns[9] = commit;
    else {
        temp = columns[index];
        columns[index] = commit;
        columnInsert(temp, index+1);
    }
}       

    /* MAYBE THROW AWAY? */

void lineFormat(node *children[], int numchildren)
{
    int i;
    char smallHead[6];
    node *child;
    char buffer[100];
    char lineone[] = "\t~~~~~~\n\t";
    char linetwo[] = "\n\t~~~~~~";

    for (i = 0; i < numchildren; i++) {
        child = children[i];
        getFirstSix(child->commitHash, smallHead);
        strcat(buffer, lineone);
        strcat(buffer, smallHead);
        strcat(buffer, linetwo);
    }
    printf("%s\n", buffer);
    strcat(printBuffer, buffer);
}

 /* how to print! */
 /*    ~~~~~~ */
 /*    18cf46 */
 /*    ~~~~~~ */

void getFirstSix(char head[], char smallHead[])
{
    int i = 0;
    for (i = 0; i < 6; i++) {
        smallHead[i] = head[i];
    }
    smallHead[6] = '\0';
}
