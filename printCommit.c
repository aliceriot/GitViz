#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "gitViz.h"

char printBuffer[10000];
char *p;
char head[40];
char tempBuffer[1000];
char lastLineCommits[1000];
char *lines[1000];

void printGraph(char cwd[], int numlines)
{
    p = printBuffer;
    headRef(head, cwd);

    // start off by adding HEAD to the first line
    strcpy(lastLineCommits, head);
    char smallHead[7];
    getFirstSix(head, smallHead);
    sprintf(tempBuffer,"    ~~~~~~\n    %s\n    ~~~~~~\n", smallHead);
    strcpy(p, tempBuffer);
    lines[0] = p;
    p += strlen(printBuffer);

    // now add the rest!
    int i;
    for (i = 1; i < numlines; i++)
        lineformat(i);

    // and print them! yeah!
    for (i = 0; i < numlines; i++)
        printf("%s", lines[i]);
}

void lineformat(int numline)
{
    // format line in tempBuffer

    strcpy(p, tempBuffer);
    lines[numline] = p;
    p += strlen(tempBuffer);
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
