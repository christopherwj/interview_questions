//create a function that uses a static variable that increments and keeps it's value
// and returns it to main and then print this value

#include <stdio.h>

int var = 10;


int foo(){
    var = var + 1;
    return var;
}

int main(){
    //int a = 10;
    //int *b = &a;
    //foo(b);
    //foo(b);
    printf("%d\n", foo());
    printf("%d\n", foo());
    printf("%d\n", foo());
    printf("%d\n", foo());
    printf("%d\n", foo());
    return 0;
}
/*the above prints:
11
12
13
14
15
*/

