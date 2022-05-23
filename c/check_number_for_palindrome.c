#include<stdio.h>    
  
int main(){    
    int n,r,reversed=0,temp; 
    n = 101;
    temp=n;    
    while(n>0){    //reversed number is stored in reversed varaible
        r=n%10;    //remainder 
        reversed=(reversed*10)+r;    
        n=n/10;    
    }    
    if(temp==sum)    //palindrome if origianl and reversed are equal
    printf("palindrome number ");    
    else    
    printf("not palindrome");    
} 
