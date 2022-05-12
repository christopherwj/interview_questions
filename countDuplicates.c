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
