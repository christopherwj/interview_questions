#include <stdio.h>
#include <stdlib.h>

int main()
{
    char i,ch1,ch2;
    printf("Enter two Alphabet of the range: ");
    scanf("%c %c",&ch1,&ch2);
//store the entered alphabets in variables ch1,ch2
    for(i=ch1; i<=ch2; i++){
     printf("%c ",i);
//display uppercase or lower case Alphabets with space
}
getch();
    return 0;
}


//version 2
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char i,ch1,ch2;
    printf("Enter the two Alphabet of the range: ");
    scanf("%c %c",&ch1,&ch2);
//store the entered alphabets in variables ch1,ch2
    i=ch1;
    while( i<=ch2){
     printf("%c ",i);
//display uppercase or lowercase Alphabets with space
 i++;
}
getch();
    return 0;
}
