#include <stdio.h>
 
//The logical-OR operator performs an inclusive-OR operation on its operands. 
//The result is 0 if both operands have 0 values. If either operand has a nonzero value, the result is 1. 
//If the first operand of a logical-OR operation has a nonzero value, the second operand isn't evaluated.

int main(){
    int n = 6;
    ((n & 1) && printf("odd")) || printf("even"); // if LSB has 1, then it has to be odd, if 0 then it is even
 
    return 0;
}
