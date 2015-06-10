#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

typedef struct node node;
struct node {
    char commitHash[42];
    node *children;
};

void headRef(char hash[], char dir[]);
void hashLocation(char hash[], char location[], char dir[]);
void commitContents(char hash[], char contents[]);
void stringShift(char s[], int shift);
void getParent(char hash[], char parents[], char dir[]);
void printGraph(char cwd[], int numlines);
void getFirstSix(char head[], char smallHead[]);
int getHashes(char buffer[], char *hashes[]);
int exists(char hash[]);
void lineformat(int numline);


// ~*~ to implement ~*~ \\

// getChildren

// addNode
// addChild
// printGraph
