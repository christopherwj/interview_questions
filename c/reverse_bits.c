//LUT  https://www.geeksforgeeks.org/reverse-bits-using-lookup-table-in-o1-time/

// C code to implement the approach
#include <stdio.h>
 
// Function to reverse bits of num
unsigned int reverseBits(unsigned int num)
{
    unsigned int count = sizeof(num) * 8 - 1;
    unsigned int reverse_num = num;
 
    num >>= 1;
    while (num) {
        reverse_num <<= 1;
        reverse_num |= num & 1;
        num >>= 1;
        count--;
    }
    reverse_num <<= count;
    return reverse_num;
}
 
// Driver's code
int main()
{
    unsigned int x = 1;
    printf("%u", reverseBits(x)); //outputs 2147483648 which is reverse of 1
    getchar();
}
