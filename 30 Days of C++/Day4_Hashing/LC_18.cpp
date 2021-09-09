// 4 Sum | Google, Amazon | Leetcode

/*Brute-force Approach : [3 POINTERS]

1. Sort the array
2. set res;
3. Under three nested loop [i, j=i+1, k=j+1]
    el = a[i] + a[j] + a[k];
    l = Binary_Search(a.begin() + k, a.end(), target - el);
    res.insert(a[i], a[j], a[k], a[l]);
    
4. Return res;*/

//Optimal Solution : [2 POINTERS]

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;

    if(nums.empty()) return res;

    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int target_2 = target - nums[i] - nums[j];
            int left = j+1, right = n-1;

            while(left < right) {
                int two_sum = nums[left] + nums[right];

                if(two_sum < target_2) left++;
                else if(two_sum > target_2) right--;
                else {
                    vector<int> quad(4,0);

                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[left];
                    quad[3] = nums[right];

                    res.push_back(quad);

                    // processing for dupplicate value for left
                    while(left < right && nums[left] == quad[2]) left++;

                    // processing for dupplicate value for right
                    while(left < right && nums[right] == quad[3]) right++;
                }
            }
            // processing for dupplicate value for j
            while(j+1 < n && nums[j+1] == nums[j]) j++;
        }
        // processing for dupplicate value for i
        while(i+1 < n && nums[i+1] == nums[i]) i++;
    }
    return res;
}

int main() {
    vector<int> nums = {-3,-2,-1,0,0,1,2,3}; int target = 0;
    vector<vector<int>> res = fourSum(nums, target);

    for (int i = 0; i < res.size(); i++)
    {
        
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<", ";
        }
        cout<<endl;
    }
}