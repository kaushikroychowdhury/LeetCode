// Subsets II | Leetcode

/* Brute-force Approach :
1. Find all the subsets.
2. Put all the elements from subsets vector to a set data-structure

Time Complexity : O(2^n + 2^n log 2^n)
*/

/*Optimal Approach : */

#include<bits/stdc++.h>
using namespace std;

 void findSubset(int index, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans) {
        ans.push_back(ds);
        
        for(int i=index; i<nums.size(); i++) {
            if(i != index && nums[i] == nums[i-1]) continue;
            
            ds.push_back(nums[i]);
            findSubset(i+1, nums, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        sort(nums.begin(), nums.end());
        
        findSubset(0, nums, ds, ans);
        return ans;
    }