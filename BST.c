int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize -1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (nums[mid] == target) {
            result = mid;
            break;
        }else {
            nums[mid] > target ? (right = mid - 1): (left = mid + 1);
        }
    }
    return result;
}
