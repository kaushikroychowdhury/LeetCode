// Count Subarrays with XOR as K | GFG

/* Brute-force Approach : 
1. Find all the Subarray
2. Calculate XOR of all the Subarray :
    if XOR is K, then Count += 1
3. Return Count

Time Complexity : O(n^3) -> O(n^2) after Optimization*/

/* Optimal Approach : [Hashing]

Time Complexity : O(n)
Space Complexity : O(n) {HASHMAP}*/

#include<bits/stdc++.h>
using namespace std;

int subarrayXOR(vector<int>& nums, int k) {
    int xorr = 0, count = 0;
    map<int, int> hashMap;

    for(int i : nums) {
        xorr = xorr ^ i;
        if(xorr == k) {
            count++;
        }
        int y = xorr ^ k;
        if(hashMap.find(y) != hashMap.end()) {
            count += hashMap[y];
        }
        hashMap[xorr] += 1;
    }
    return count;
}

int main() {
    vector<int> nums = {4,2,2,6,4};
    cout<<subarrayXOR(nums, 6);
}