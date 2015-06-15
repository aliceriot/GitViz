#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

    /* DATA INPUT */

int getHashes(char buffer[], char *hashes[]);

    /* TREE OPERATIONS */

typedef struct node node;
struct node {
    char *commitHash; // these are already in an array!
    node *children[10]; // pointers to other nodes (children of this commit)
    node *parents[10];
    int numchildren;
    int numparents;
};

void treeInit(char  *commits[], int numcommits);
int addNode(char hash[]);
void addChildren(char child[]);
void addParents(char child[]);
void insertChild(node *parent, node *child);
void insertParent(node *child, node *parent);
node *getNode(char commit[]);
void printNodeHashes();
void printHash(int index);
void deinitialize(int numcommits);
void initialize();

    /* HASHTABLE */

typedef struct nlist nlist;
struct nlist {
    struct nlist *next;
    char *name;
    int index;
};
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, int index);

    /* PRINTING */

void printGraph(char *commits[], int numcommits);
void getFirstSix(char head[], char smallHead[]);
void lineFormat(node *children[], int numchildren);
int findColumn(char *hash);
void columnDelete(int index);

    /* UTILITY/MISC */

void headRef(char hash[], char dir[]);
void hashLocation(char hash[], char location[], char dir[]);
void commitContents(char hash[], char contents[]);
void stringShift(char s[], int shift);
int getParent(char hash[], char *parents[]);
