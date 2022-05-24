
/*
0011 1110 0101 1011 0001 1101
  3    E    5    B   1    D

https://www.tutorialspoint.com/how-to-convert-binary-to-hex-by-using-c-language

To convert from binary to hex representation, the bit string id is grouped in blocks of 4-bits which are called as nibbles 
from the least significant side. Each block is replaced by the corresponding hex digit.
*/

#include <stdio.h>
int main(){
   long int binaryval, hexadecimalval = 0, i = 1, remainder;
   printf("Enter the binary number: ");
   scanf("%ld", &binaryval);
   while (binaryval != 0){
      remainder = binaryval % 10;
      hexadecimalval = hexadecimalval + remainder * i;
      i = i * 2;
      binaryval = binaryval / 10;
   }
   printf("Equivalent hexadecimal value: %lX", hexadecimalval);
   return 0;
}
