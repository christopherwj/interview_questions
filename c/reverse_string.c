#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

char *str = "Hello";

void reverseString(char *arr, size_t arrSize){
    char temp[arrSize];
    int cnt = 0;
    for (int i = arrSize - 1 ; i >= 0; --i){
            temp[cnt++] = arr[i];
            if(cnt == arrSize){temp[cnt++]='\0';};
        }
    printf("%s", temp);
}

int main() {
    reverseString(str, 5);
    return 0;
}
