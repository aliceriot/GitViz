#include <stdio.h>
#include "gitViz.h"

void stringShift(char s[], int shift)
{
    int i;

    for (i = shift; i < strlen(s); i++)
        s[i - shift] = s[i];
    i -= shift;
    s[i] = '\0';
}
