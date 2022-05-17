#include <stdio.h>

int sum(int num1, int num2, int* sum){
    return *sum = num1+ num2;
}

int main()
{
    int a = 1;
    int b = 2;
    int c;
    
    int d = sum(a,b, &c);
    printf("%d", d);

    return 0;
}
