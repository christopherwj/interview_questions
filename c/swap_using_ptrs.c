#include <stdio.h>

void swap(int* a, int* b) 
{
	int t = *a;
	*a = *b;
	*b = t;

}

int main()
{
    int a = 10;
    int b = 20;
    printf("%d", a);
    printf("%d", b);
    swap(&a, &b);
    printf("%d", a);
    printf("%d", b);
    return 0;
}
