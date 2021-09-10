// Largest Subarray with 0 Sum | LeetCode

/* Brute-force Approach : 
1. Find all the Subarray and Check which subarray sum is 0
2. return the largest subarray's length.

Time Complexity : O(n^2)
Space Complexity : O(1)*/

/* Optimal Approach : [HASHING]
Time and Space Complexity : O(n)*/

#include<bits/stdc++.h>
using namespace std;

int largestSubarray(vector<int>& nums) {
    int maxLength = 0, sum = 0;
    map <int, int> hashMap;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if(sum == 0) {
            maxLength = max(maxLength, (i-0)+1);
        }

        else if(hashMap.find(sum) == hashMap.end()) {
            hashMap[sum] = i;
        }

        else {
            maxLength = max(maxLength, (i - hashMap[sum]));
        }
    }
    return maxLength;
}

int main() {
    vector<int> nums = {1, -1, 3, 2, -2, -8, 1, 7, 10, 23};
    cout<<largestSubarray(nums);
}