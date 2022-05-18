
// A O(n^2) time and O(1) space
// program to find the longest
// palindromic substring
#include <stdio.h>
#include <string.h>
 
// A utility function to print
// a substring str[low..high]
void printSubStr(char* str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        printf("%c", str[i]);
}
 
// This function prints the longest
// palindrome substring (LPS)
// of str[]. It also returns the
// length of the longest palindrome
int longestPalSubstr(char* str)
{
    int n = strlen(str); // calculating size of string
    if (n < 2)
        return n; // if string is empty then size will be 0.
                  // if n==1 then, answer will be 1(single
                  // character will always palindrome)
 
    int maxLength = 1,start=0;
    int low, high;
    for (int i = 0; i < n; i++) {
        low = i - 1;
        high = i + 1;
        while ( high < n && str[high] == str[i]) //increment 'high'                                  
            high++;
       
        while ( low >= 0 && str[low] == str[i]) // decrement 'low'                   
            low--;
       
        while (low >= 0 && high < n && str[low] == str[high]){
              low--; // decrement low
            high++; // increment high
        }
 
        int length = high - low - 1;
        if (maxLength < length) {
            maxLength = length;
              start=low+1;
        }
    }
    printf("Longest palindrome substring is: ");
      printSubStr(str,start,start+maxLength-1);
    return maxLength;
}
 
// Driver program to test above functions
int main()
{
    char str[] = "forgeeksskeegfor";
    printf("\nLength is: %d", longestPalSubstr(str));
    return 0;
}
