/**
 * C program to print ASCII values of all characters.
 */
 //https://codeforwin.org/2015/06/c-program-to-print-ascii-values-of-all-characters.html

#include <stdio.h>

int main()
{
    int i;

    /* Print ASCII values from 0 to 255 */
    for(i=0; i<=255; i++) 
    {
        printf("ASCII value of character %c = %d\n", i, i);
    }

    return 0;
}
