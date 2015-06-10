#include <stdio.h>

// define our new data type
typedef struct Node {
    char commitHash[42];
    node *children[10];
} node;

node *treeIndex[100];


