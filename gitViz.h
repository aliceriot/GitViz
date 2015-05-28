#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void headRef(char hash[], char dir[]);
void hashLocation(char hash[], char location[], char dir[]);
void commitContents(char hash[], char contents[]);
void stringShift(char s[], int shift);
void getParent(char hash[], char parents[], char dir[]);

// ~*~ to implement ~*~ \\

//int headless(char hash[]);

//int printCommit(char hash[]);
