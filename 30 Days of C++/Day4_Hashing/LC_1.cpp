// Two Sum | LeetCode

/* Brute-force*/
/* Optimal Approach : (Hashing)

1.map hash <el, value>

2. Traverse through the array;
    b   el = target - a[i];
    c   if(el in hash) return(i, el->value)
    d   else hash(nums[i],i)

Time Complexity : O(N)
Space Complexity : O(N) for HASH-MAP*/

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> hash;
    int el;
    for (int i = 0; i < nums.size(); i++)
    {
        el = target - nums[i];
        if(hash.find(el) == hash.end()) {
            hash[nums[i]] = i;
        }
        else {
            return {hash[el], i};
        }
    }
}

int main() {
    vector<int> nums = {3,3};
    vector<int> res = twoSum(nums,6);
    cout<<res[0]<<", "<<res[1];
}