//https://www.geeksforgeeks.org/program-decimal-binary-conversion/

#include<stdio.h>
int main()
{
    int bin,rem,dec=0,j=1;
    printf("Enter the any binary number:");
    scanf("%d",&bin);
    while(bin!=0)
    {
        rem=bin%10;
        dec=dec+rem*j;
        j=j*2;
        bin=bin/10;
    }
    printf("Decimal number is:%d",dec);
}

// Output:
// Enter the any binary number:101010
// Decimal number is:42
