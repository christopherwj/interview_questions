 
#include <stdio.h>
 
int main(void) {
 
   int firstnum, secondnum;
   int prod = 0,i;
 
   printf("Enter two numbers \n");
   scanf("%d %d",&firstnum,&secondnum);
 
   for(i = 1; i <= secondnum; i++){
     /* Add the value of firstnum in prod. */
     //we are adding the first number the amounf of the second number
     prod += firstnum;
   }
   printf("Multiplication of two numbers is %d",prod);
   return 0;
} 
