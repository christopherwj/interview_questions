#include <stdio.h>

int c;

void foo(int a, int b) {
  c = a + b;
}

int main(void)
{

    int a = 1, b = 1;
    foo(a,b);
    //print("%d", c);
    return 0;
}
