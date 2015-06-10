#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

typedef struct node node;
struct node {
    char *commitHash; // these are already in an array!
    node *children; // pointers to other nodes (children of this commit)
};

void headRef(char hash[], char dir[]);
void hashLocation(char hash[], char location[], char dir[]);
void commitContents(char hash[], char contents[]);
void stringShift(char s[], int shift);
void getParent(char hash[], char parents[], char dir[]);
void printGraph(char cwd[], int numlines);
void getFirstSix(char head[], char smallHead[]);
int getHashes(char buffer[], char *hashes[]);
void lineformat(int numline);
void initialize();
int addNode(char hash[]);
void printNodeHashes();


// ~*~ to implement ~*~ \\

// getChildren

// addNode
// addChild
// printGraph
