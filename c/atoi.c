//https://www.geeksforgeeks.org/write-your-own-atoi/


// Program to implement atoi() in C
#include <stdio.h>
 
// A simple atoi() function
int myAtoi(char* str)
{
    // Initialize result
    int res = 0;
 
    // Iterate through all characters
    // of input string and update result
    // take ASCII character of corresponding digit and
    // subtract the code from '0' to get numerical
    // value and multiply res by 10 to shuffle
    // digits left to update running total
    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
 
    // return result.
    return res; //returns 89789
}
 
// Driver Code
int main()
{
    char str[] = "89789";
   
    // Function call
    int val = myAtoi(str);
    printf("%d ", val);
    return 0;
}


// ======================================================
//handles negative number
// Program to implement atoi() in C
// A C program for
// implementation of atoi
#include <stdio.h>
 
// A simple atoi() function
int myAtoi(char* str)
{
    // Initialize result
    int res = 0;
 
    // Initialize sign as positive
    int sign = 1;
 
    // Initialize index of first digit
    int i = 0;
 
    // If number is negative,
    // then update sign
    if (str[0] == '-') {
        sign = -1;
 
        // Also update index of first digit
        i++;
    }
 
    // Iterate through all digits
    // and update the result
    for (; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
 
    // Return result with sign
    return sign * res; // returns -123
}
 
// Driver code
int main()
{
    char str[] = "-123";
   
    // Function call
    int val = myAtoi(str);
    printf("%d ", val);
    return 0;
}
