https://www.geeksforgeeks.org/subtract-1-without-arithmetic-operators/

// C code to subtract
// one from a given number
#include <stdio.h>
 
int subtractOne(int x)
{
    int m = 1;
 
    // Flip all the set bits
    // until we find a 1
    while (!(x & m)) {
        x = x ^ m;
        m <<= 1;
    }
 
    // flip the rightmost 1 bit
    x = x ^ m;
    return x;
}
 
/* Driver program to test above functions*/
int main()
{
    printf("%d", subtractOne(13));
    return 0;
}
