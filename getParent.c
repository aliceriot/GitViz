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

    printf("%s\n\n", contents);

    sscanf(contents, "%s\t", scratch);

    i = 1;
    /// FIX THIS!
    while (i < numlines) {
        sscanf(contents, "%s\t", line);
        printf("%s\n\n", line);
        if (line[0] == 'p') {
            sscanf(line, "%*s _ %s", scratch);
            strcat(parents, scratch);
            strcat(parents, "_");
        }
        stringShift(contents, strlen(line));
        i++;
    }
    /// TO HERE!

    printf("%s\n\n", contents);
    printf("%s\n\n", scratch);
    printf("%s\n\n", parents);
}
