// 3 Sum | LeetCode

/*Brute-force Approach : 

1. Sort the array
2. set res;
3. Under three nested loop [i, j=i+1]
    el = a[i] + a[j];
    k = Binary_Search(a.begin() + j, a.end(), target - el);
    res.insert(a[i], a[j], a[k]);
    
4. Return res;

Time Complexity : O(n^3*log n) + O(nlogn)
Space Complexity : O(n) set*/

// Optimal Approach : [2 Pointers without Binary Search]

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;

    if(nums.empty()) return res;

    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int left = i+1, right = n-1;
        int target_2 = 0 - nums[i];
        while(left < right) {
            int two_sum = nums[left] + nums[right];

            if(two_sum < target_2) left++;
            else if(two_sum > target_2) right--;

            else
            {
                vector<int> triplet(3,0);
                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];

                res.push_back(triplet);

                while(left < right && nums[left] == triplet[1]) ++left;

                while(left < right && nums[right] == triplet[2]) --right;
            }
        }
        while(i+1 < n && nums[i+1] == nums[i]) ++i;
    }
    return res;
}

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(nums);

    for (int i = 0; i < res.size(); i++)
    {
        
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<", ";
        }
        cout<<endl;
    }
}