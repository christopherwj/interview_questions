// C program to convert a real value
// to IEEE 754 floating point representation
 
#include <stdio.h>
 
void printBinary(int n, int i)
{
 
    // Prints the binary representation
    // of a number n up to i-bits.
    int k;
    for (k = i - 1; k >= 0; k--) {
 
        if ((n >> k) & 1)
            printf("1");
        else
            printf("0");
    }
}
 
typedef union {
 
    float f;
    struct
    {
 
        // Order is important.
        // Here the members of the union data structure
        // use the same memory (32 bits).
        // The ordering is taken
        // from the LSB to the MSB.
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
 
    } raw;
} myfloat;
 
// Function to convert real value
// to IEEE floating point representation
void printIEEE(myfloat var)
{
 
    // Prints the IEEE 754 representation
    // of a float value (32 bits)
 
    printf("%d | ", var.raw.sign);
    printBinary(var.raw.exponent, 8);
    printf(" | ");
    printBinary(var.raw.mantissa, 23);
    printf("\n");
}
 
// Driver Code
int main()
{
 
    // Instantiate the union
    myfloat var;
 
    // Get the real value
    var.f = -2.25;
 
    // Get the IEEE floating point representation
    printf("IEEE 754 representation of %f is : \n",
           var.f);
    printIEEE(var);
 
    return 0;
}

mantissa:

 seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm    meaning
31                              0    bit #

s = sign bit, e = exponent, m = mantissa

IEEE 754 representation of -2.250000 is : 
1 | 10000000 | 00100000000000000000000
  
//==============================================================
  //floating point to real
  
// C program to convert
// IEEE 754 floating point representation
// into real value
 
#include <math.h>
#include <stdio.h>
 
typedef union {
 
    float f;
    struct
    {
 
        // Order is important.
        // Here the members of the union data structure
        // use the same memory (32 bits).
        // The ordering is taken
        // from the LSB to the MSB.
 
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
 
    } raw;
} myfloat;
 
// Function to convert a binary array
// to the corresponding integer
unsigned int convertToInt(int* arr, int low, int high)
{
    unsigned f = 0, i;
    for (i = high; i >= low; i--) {
        f = f + arr[i] * pow(2, high - i);
    }
    return f;
}
 
// Driver Code
int main()
{
 
    // Get the 32-bit floating point number
    unsigned int ieee[32]
        = { 1,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0 };
 
    myfloat var;
 
    // Convert the least significant
    // mantissa part (23 bits)
    // to corresponding decimal integer
    unsigned f = convertToInt(ieee, 9, 31);
 
    // Assign integer representation of mantissa
    var.raw.mantissa = f;
 
    // Convert the exponent part (8 bits)
    // to a corresponding decimal integer
    f = convertToInt(ieee, 1, 8);
 
    // Assign integer representation
    // of the exponent
    var.raw.exponent = f;
 
    // Assign sign bit
    var.raw.sign = ieee[0];
 
    printf("The float value of the given"
           " IEEE-754 representation is : \n");
    printf("%f", var.f);
}

The float value of the given IEEE-754 representation is : 
-2.250000
