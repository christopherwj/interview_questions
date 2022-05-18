#include <stdio.h>
 
// Two pointer technique based solution to find
// if there is a pair in A[0..N-1] with a given sum.
int isPairSum(int A[], int N, int X)
{
    // Represents first pointer
    int i = 0;
 
    // Represents second pointer
    int j = N - 1;
 
    while (i < j)
    {
        // If we find a pair
        if (A[i] + A[j] == X)
            return 1;
 
        // If sum of elements at current
        // pointers is less, we move towards
        // higher values by doing i++
        else if (A[i] + A[j] < X)
            i++;
 
        // If sum of elements at current
        // pointers is more, we move towards
        // lower values by doing j--
        else
            j--;
    }
    return 0;
}
 
// Main method
int main()
{
    // Array declaration MUST BE SORTED
    int arr[] = { 2, 3, 5, 8, 9, 10, 11 };
     
    // Custom value to be searched
    int val = 17;
     
    // size of the array
    int arrSize = sizeof(arr) / sizeof(arr[0]);
   
    // Function call
    printf("%d", isPairSum(arr, arrSize, val));  
    //this will return 1 since 8+9 = 17, and that's the only case thus 1
 
    return 0;
}
