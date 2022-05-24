//Implicit Type Conversion is also known as ‘automatic type conversion‘. It is done by the compiler on its own, without any external trigger from the user. 
//It generally takes place when in an expression more than one data type is present. 

//https://www.geeksforgeeks.org/implicit-type-conversion-in-c-with-examples/

// C program to demonstrate Implicit
// Type Conversion of numeric types
  
#include <stdbool.h>
#include <stdio.h>
  
int main(void)
{
    // Local Declarations
    bool b = true;
    char c = 'X';
    float d = 1234.5;
    int i = 123;
    short s = 98;
  
    // Statements
    printf("bool + char is char:     %c\n", b + c);
    printf("int * short is int:      %d\n", i * s);
    printf("float * char is float:   %f\n", d * c);
  
    // bool promoted to char
    c = c + b;
  
    // char promoted to float
    d = d + c;
  
    b = false;
  
    // float demoted to bool
    b = -d;
  
    printf("\nAfter execution \n");
    printf("char + true:     %c\n", c);
    printf("float + char:    %f\n", d);
    printf("bool = -float:   %d\n", b);
  
    return 0;
}
