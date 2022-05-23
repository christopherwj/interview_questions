#include<stdio.h>

void fun();

int main(){
  fun();
  fun();
  fun();
  return 0;
}

void fun(){
  int a = 1;
  static int b = 10;
  printf("a = %dn", a); //prints 1 everytime
  printf("b = %dnn", b);  // prints 10 11 12 
  a++;
  b++;
}
