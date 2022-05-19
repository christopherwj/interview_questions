https://www.geeksforgeeks.org/subtract-two-numbers-without-using-arithmetic-operators/

// C program to Subtract two numbers
// without using arithmetic operators
#include<stdio.h>
 
int subtract(int x, int y)
{
    // Iterate till there
    // is no carry
    while (y != 0)
    {
        // borrow contains common
        // set bits of y and unset
        // bits of x
        int borrow = (~x) & y;
 
        // Subtraction of bits of x
        // and y where at least one
        // of the bits is not set
        x = x ^ y; //XOR is ^, OR is |
 
        // Borrow is shifted by one
        // so that subtracting it from
        // x gives the required sum
        y = borrow << 1;
    }
    return x;
}
 
// Driver Code
int main()
{
    //int x = 0x08, y = 0x04; this works returns 0x04, vice versa works and returns -4 think 2's complement
    int x = 4, y = 4;
    printf("x - y is %d", subtract(x, y));
    return 0;
}
