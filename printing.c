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
    memset(columns, 0, 10*sizeof(node *));
    
    char line[100];
    memset(line, '\0', 100*sizeof(char));
    // asciiColumns(3, line);

    // printf("%s\n", line);

    asciiSplit(5, 2, line);
    
    printf("%s\n", line);
}
        
    /* COLUMN INDEX HANDLING */

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

    /* PRINTING / ASCII */

void getFirstSix(char head[], char smallHead[])
{
    int i = 0;
    for (i = 0; i < 6; i++) {
        smallHead[i] = head[i];
    }
    smallHead[6] = '\0';
}

void asciiColumns(int numbranches, char *line)
{ // numbranches is number of columns to the left
    int i;
    for (i = 0; i < numbranches*2; i +=2) {
        line[i] = '|';
        line[i+1] = ' ';
    }
}

void asciiSplit(int splits, int column, char *line)
{ // splits is number of total children
    int i, j = 0;
    for (i = 0; i < splits-1; i++) {
        for (j = 0; j < column; j++)
            strcat(line, "| ");
        for (j = 0; j < i; j++)
            strcat(line, "| ");
        strcat(line, "| \\\n");
    }
    for (j = 0; j < splits+column; j++)
        strcat(line, "| ");
    strcat(line, "\n");
}
       
    



