/*
 * C Program to Convert Binary to Octal
 * https://www.embeddedc.in/p/c-program-for-binary-to-octal-conversion.html
 */
 #include <stdio.h>
 
#include<stdio.h>
int main()
{
    int number,octnumber=0,a=1,remainder;
    printf("Enter the binary number:");
    scanf("%d",&number);
    while(number!=0)
    {
        remainder=number%10;
        octnumber=octnumber+remainder*a;
        a=a*2;
        number=number/10;
    }
     printf("Octal number:%o", octnumber);
}
