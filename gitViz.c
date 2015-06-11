#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "gitViz.h"


void main()
{
    char buffer[20000];
    char *commits[1000];
    int numcommits, i;

    numcommits = getHashes(buffer, commits);
    treeInit(commits, numcommits);

    char root[42];
    strcpy(root, commits[0]);

    // printNodeHashes();

/*     node *myptr; */
/*     myptr = getNode("783ca773ec163d72a8537cc5c177f12d83d508e0"); */
/*     printf("%s\n", myptr->commitHash); */
/*     printf("testing printgraph: \n\n"); */

/*     printGraph(root); */
    
    for (i = 0; i < numcommits; i++) {
        node *myptr;
        myptr = getNode(commits[i]);
        printf("Commit: %s\nChildren: ", myptr->commitHash);
        printGraph(myptr->commitHash);
        printf("\n");
    }

       

    deinitialize(numcommits);
}


