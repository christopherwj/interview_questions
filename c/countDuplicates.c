=================================================================================
//code below works to count the amount of duplicates
#include <stdlib.h>
#include <stdbool.h>

int cmp_chars(const void *a, const void *b)
{
    return *(char*)a - *(char*)b;
}

int i;

int main() {
    char canvas[] = "aabbc";
    
    qsort(canvas, sizeof(canvas) - 1, sizeof(canvas[0]), cmp_chars);
    
    for (char *p = canvas; p[1] != '\0'; ++p) {
        if (p[0] == p[1]) {
            i++;
        }
    }
    printf("%d", i); //print the number of duplicates
}  
=================================================================================
// returns true if a duplicate is found
#include <stdlib.h>
#include <stdbool.h>

int cmp_chars(const void *a, const void *b)
{
    return *(char*)a - *(char*)b;
}

int main() {
    char canvas[] = "abc";
    
    qsort(canvas, sizeof(canvas) - 1, sizeof(canvas[0]), cmp_chars);
    
    bool duplicate_found = false;
    for (char *p = canvas; p[1] != '\0'; ++p) {
        if (p[0] == p[1]) {
            duplicate_found = true;
            break;
        }
    }
    
    printf("'%s' %s duplicates\n",
        canvas,
        duplicate_found ? "has" : "does not have");
}
