#include <stdio.h>

void foo(int a, int b) {
  static int c = 1;
  c = a + b;
  //return c;
}

int main(void)
{

    int a = 1, b = 1;
    foo(a,b);
    //print("%d", c);
    return 0;
}
