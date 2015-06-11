#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getHashes(char buffer[], char *hashes[]);

//tree related stuff
typedef struct node node;
struct node {
    char *commitHash; // these are already in an array!
    node *children; // pointers to other nodes (children of this commit)
};
void initialize();
int addNode(char hash[]);
void printNodeHashes();
void deinitialize(int numcommits);
void printHash(int index);

void headRef(char hash[], char dir[]);
void hashLocation(char hash[], char location[], char dir[]);
void commitContents(char hash[], char contents[]);
void stringShift(char s[], int shift);
void getParent(char hash[], char parents[]);
void printGraph(char cwd[], int numlines);
void getFirstSix(char head[], char smallHead[]);
void lineformat(int numline);

// hashtable stuff
typedef struct nlist nlist;
struct nlist {
    struct nlist *next;
    char *name;
    int index;
};
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, int index);


// ~*~ to implement ~*~ \\

// getChildren

// addNode
// addChild
// printGraph
