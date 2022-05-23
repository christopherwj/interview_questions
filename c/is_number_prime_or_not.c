/*C PROGRAM EXAMPLE FOR PRIME NUMBER:
What is prime number?


A number is considered as prime number when it satisfies the below conditions.

It should be whole number
It should be greated than 1
It should have only 2 factors. They are, 1 and the number itself.
Example for prime numbers: 2, 3, 5, 7, 11, 13, 17, 19, 23 etc.

Why 4, 6, 8, 9, 10, 12, 14, 15, 16 etc are not prime numbers?

Because, the number 4 can be factored as 2*2 and 1*4. As per the rule of prime number, there should be 2 factors only. 
They are 1 and the number itself. But, number 4 has 2*2 also. Like this, all remaining numbers 6, 8, 9, 10, 12, 14, 15, 16 have factors other than 1 and the number itself. So, these are not called as prime numbers.
*/

#include <stdio.h>
int main()
{
   int i, num, p = 0;
   printf("Please enter a number: \n");
   scanf("%d", &num);
   for(i=1; i<=num; i++)
   {
      if(num%i==0)
      {
         p++;
      }
   }
   if(p==2)
   {
      printf("Entered number is %d "\
             "and it is a prime number.",num);
   }
   else
   {
      printf("Entered number is %d "\
             "and it is not a prime number.",num);
   }
}
