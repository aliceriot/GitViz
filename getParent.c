#include <stdio.h>
#include <string.h>
#include "gitViz.h"

void getParent(char hash[], char parents[], char dir[])
{
    char contents[MAXLINE];
    char line[MAXLINE];
    char scratch[MAXLINE];
    int i, numlines = 0;

    commitContents(hash, contents);

    // hacky thing
    for (i=0; i<strlen(contents); i++)
        if (contents[i] == '\n') {
            contents[i] = '\t';
            numlines++;
        }
        else if (contents[i] == ' ')
            contents[i] = '_';

    i = 1;
    parents[0] = '\0';

    /// FIX THIS!
    while (i < numlines) {
        // should get 1st line
        sscanf(contents, "%s\t", line);
        if (line[0] == 'p') {
            sscanf(line, "parent_%s", scratch);
            strcat(parents, scratch);
            strcat(parents, " ");
        }
        stringShift(contents, strlen(line));
        i++;
    }
}
