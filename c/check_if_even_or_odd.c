#include <stdio.h>
#include <stdbool.h>

bool isEven(int a){
    if(a%2==0){return true;}
    else return false;
}

int main()
{
    //printf("Hello World");
    printf("%d", isEven(2));

    return 0;
}
