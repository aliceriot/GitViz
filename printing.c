#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "gitViz.h"

char printBuffer[10000];
int columns[10];

void printGraph(char *commits[], int numcommits)
{
    //printInitialize();
    memset(columns, -1, 10*sizeof(int));
    node *commit, *tempone, *temptwo, *childptr;
    char smallHash[6];
    char *p = printBuffer;
    char line[200];
    
    int i, j, parents, children, numbranches;

    // handle root first
    memset(line, '\0', 100*sizeof(char));
    commit = getNode(commits[0]);
    getFirstSix(commit->commitHash, smallHash);
    columnInsert(commit->key, 0);
    asciiCommit(1, 0, line);
    strcat(line, smallHash);
    printf("%s\n", line);
    numbranches = 1;
    childptr = commit->children[0];
    columns[0] = childptr->key;
    for (i = 1; i < commit->numchildren; i++) {
        columnInsert((commit->children[i])->key, i);
        printf("yikes!\n");
    }

    int numpar, numchild, index1, index2;
    // the rest of the commits!
    for (i = 1; i < numcommits; i++) {
        memset(line, '\0', 100*sizeof(char));
        commit = getNode(commits[i]);
        getFirstSix(commit->commitHash, smallHash);
        numpar = commit->numparents;
        numchild = commit->numchildren;

            /* MERGING */

        if (numpar > 1) { 
            for (j = 1; j < numpar; j++) {
                tempone = commit->parents[j-1];
                index1 = findColumn(commit->commitHash, 9);
                temptwo = commit->parents[j];
                index2 = findColumn(commit->commitHash, index1-1);
                if (index1 < index2) {
                    asciiMerge(index1, index2, numbranches - index2, line);
                    columnDelete(index2);
                }
                else {
                    asciiMerge(index2, index1, numbranches - index1 -1, line);
                    columnDelete(index1);
                }
                numbranches--;
            }
        }   
        
            /* COMMIT LINE */

        index1 = findColumn(commit->commitHash, 9);
        asciiCommit(numbranches, index1, line);
        strcat(line, smallHash);
        strcat(line, "\n");

            /* BRANCHING */

        if (numchild == 1) { // don't branch
            childptr = commit->children[0];
            columns[index1] = childptr->key;
        } else if (numchild == 0) {
        } else { // need to branch
            childptr = commit->children[0];
            columns[index1] = childptr->key;
            for (j = 1; j < numchild; j++) {
                childptr = commit->children[j];
                columnInsert(childptr->key, index1+j);
                numbranches++;
            }
            asciiSplit(numchild, index1, line);
        }
        strcpy(p, line);
        p += strlen(line);
    }
    printf("%s\n", printBuffer);
}
        
    /* COLUMN INDEX HANDLING */

// return the rightmost column for a commit
int findColumn(char *hash, int start)
{ // start is where to start searching
    int i, key;
    node *ptr = getNode(hash);
    key = ptr->key;
    for (i = start; i >= 0; i--) {
        if (columns[i] == key)
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
void columnInsert(int key, int index)
{
    int temp;
    if (index == 9)
        columns[9] = key;
    else {
        temp = columns[index];
        columns[index] = key;
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

void asciiCommit(int branches, int commit, char *line)
{
    int i;
    for (i = 0; i < branches; i++) {
        if (i == commit)
            strcat(line, "* ");
        else
            strcat(line, "| ");
    }
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
       
// lets us draw a merge from right to left (indices)
void asciiMerge(int left, int right, int extra, char *line)
{ // extra is stuff to the right
    int i, j;
    strcat(line, "|");
    for (i = 0; i < left; i++)
        strcat(line, " |");
    for (i = left; i < right -1; i++)
        strcat(line, " |_");
    strcat(line, "/ ");
    if (extra != 0) {
        for (i = right; i < extra+1; i++)
            strcat(line, "| ");
    }
    strcat(line, "\n");
}
