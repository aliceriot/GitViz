#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gitViz.h"
        
    /* GET THOSE PARENTS! */

int getParent(char hash[], char *parents[])
{
    char contents[MAXLINE];
    char line[MAXLINE];
    char scratch[42];
    int i, numlines = 0;
    char *temp;

    commitContents(hash, contents);

    for (i=0; i<strlen(contents); i++)
        if (contents[i] == '\n') {
            contents[i] = '\t';
            numlines++;
        }
        else if (contents[i] == ' ')
            contents[i] = '_';
    i = 1;
    int j = 0;
    while (i < numlines) {
        sscanf(contents, "%s\t", line);
        if (line[0] == 'p') {
            sscanf(line, "parent_%s", scratch);
            temp = malloc(sizeof(scratch));
            strcpy(temp, scratch);
            parents[j++] = temp;
        }
        stringShift(contents, strlen(line));
        i++;
    }
    return j;
}
