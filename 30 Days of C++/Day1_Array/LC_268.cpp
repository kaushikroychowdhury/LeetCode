// Find the Missing and repeating number | GFG
// Missing Number | LeetCode

/* Brute force Approach OR Naive approach

1. traverse the nums vector    O(n)
2. store the occurrences in another array (hashing Technique)

Example :  nums = {4, 3, 6, 2, 1, 1}
Hashed Array = {0,2,1,1,1,0,1}

Value at index 1 is greater than 1, hence repeating number is 1
Value at index 5 is 0, hence missing number is 5

O(n) + O(n) = O(2n)     time complexity
O(n)        Space complexity*/



#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {

    long n = nums.size();
    long s = (n*(n+1))/2;   // Basic Math Formula
    long long s_sq = (n*(n+1)*(2*n+1))/6;
    long num_s = 0, num_sq = 0;
    for(auto it : nums) {
        num_s += it;
        num_sq += (it*it);
    }

    long r1 = s-num_s;
    long long r2 = s_sq-num_sq;

    r2 = r2/r1;
    int missing = (r2+r1)/2;
    // int repeat = r2-missing;

    return missing;
}

int main() {
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    cout<<missingNumber(nums);
}

// there is a XOR methid     Doesn't Understand at all