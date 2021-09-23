// Remove Duplicates from Sorted Array

/*Brute-force Approach : [HASHING]
1. Traverse the array
    a. store every element in set (set don't store duplicate values)

2. Traverse the set
    a. Replace set.size() elements of the array from the beginning with the set elements

Time Complexity : O(NlogN) + O(N)
Space Complexity : O(N)
*/

/*Optimal Approach [2-POINTERS]

Time Complexity : O(n)
Space Complexity : O(1)*/

#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0) return 0;

    int i=0, j=0, n = nums.size();

    while(j < n) {
        if(nums[i] == nums[j]) {
            j += 1;
        }
        else {
            i += 1;
            nums[i] = nums[j];
            j += 1;
        }
    }
    return i+1;
}