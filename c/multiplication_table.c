#include <stdio.h>
void main()
{
   int j,i,n;
   printf("Input upto the table number starting from 1 : ");
   scanf("%d",&n);
   printf("Multiplication table from 1 to %d \n",n);
   for(i=1;i<=10;i++) // this is producing rows
   {
     for(j=1;j<=n;j++) // this is producing columns
     {
       if (j<=n-1)
           printf("%d, ",i*j);
          else
	    printf("%d ",i*j);

      }
     printf("\n");
    }
} 
