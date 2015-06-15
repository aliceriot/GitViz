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
int findColumn(char *hash);
void columnDelete(int index);
void columnInsert(node *commit, int index);
void asciiColumns(int numbranches, char *line);
void asciiSplit(int splits, int column, char *line);
void asciiMerge(int left, int right, int extra, char *line);

    /* UTILITY/MISC */

void headRef(char hash[], char dir[]);
void hashLocation(char hash[], char location[], char dir[]);
void commitContents(char hash[], char contents[]);
void stringShift(char s[], int shift);
int getParent(char hash[], char *parents[]);
