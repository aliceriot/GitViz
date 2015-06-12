#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "gitViz.h"

char printBuffer[10000];
char *p;
char tempBuffer[1000];
char lastLineCommits[1000];
char *lines[1000];

void printGraph(char rootHash[])
{
    node *root = getNode(rootHash);
    node *child;
    int num = root->numchildren;
    int i;
    for (i = 0; i < num; i++) {
        char hash[42];
        child = root->children[i];
        printf("%s\n", child->commitHash);
    }
    printf("%s\n", printBuffer);
}

        

void lineformat(node *children[], int numchildren)
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
