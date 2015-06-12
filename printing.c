#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "gitViz.h"

char printBuffer[10000];
node *columns[10];




void printGraph(char rootHash[], int numcommits)
{
    //printInitialize();
    node *root = getNode(rootHash);
    node *commit;
    
    lineFormat(rootHash);
    columns[0] = root;

    int i,j;
    for (i = 0; i < numcommits; i++) {
        commit = getNode(commits[i]);
        int numcols
        if (commit->numparents == 1)


                

        


    }
}
        
    /* TO IMPLEMENT */

// return the rightmost column for a commit
int findColumn(char *hash);

// remove a particular column index (do all 
// the shifting and stuff)
void columnShift(int index);

// insert a number of columns for a commit at a location
void columnInsert(char *hash, int numchildren, int index);

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
