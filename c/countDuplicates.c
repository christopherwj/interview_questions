//take in a string using pointers and count the amount of duplicates that exist

static int _cmp(const int *l, const int *r){
    return (*l-*r);
}
1,2,2,2,3,3,4,4,4,4,4,4,4,5,5
bool containsduplicate(int *nums, int numsSize){
    if(nums == 0x0 || nums.length == 0) return false;
  
qsort(nums, numsSize, sizeof(int), _cmp);
  int l = numsSize;
  for(int i = 1; i < l; i++){
      if(nums[i-l] == nums[i]){
        cnt++;
            while(nums[i-l] == nums[i])
      i++;
    }
  }
  return false;
}


//code below works
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
    
    bool duplicate_found = false;
    for (char *p = canvas; p[1] != '\0'; ++p) {
        if (p[0] == p[1]) {
            duplicate_found = true;
            //break;
            i++;
        }
    }
    
    //printf("'%s' %s duplicates\n",
    //    canvas,
    //   duplicate_found ? "has" : "does not have");
    printf("%d", i);
}  
