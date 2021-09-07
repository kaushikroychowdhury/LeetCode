// Majority Element II

/**/

#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {        // Boyer Moore Voting Algorithm
    int num1 = -1, num2 = -1, c1 = 0, c2 = 0, el = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        el = nums[i];
        if(num1 == el) c1++;
        else if(num2 == el) c2++;
        else if(c1 == 0) {
            num1 = el;
            c1++;
        }
        else if(c2 == 0) {
            num2 = el;
            c2++;
        }
        else {
            c1--;
            c2--;
        }
    }

    vector<int> res;
    c1 = c2 = 0;
    for(int i =0; i<nums.size(); i++) {
        if(nums[i] == num1) c1++;
        else if(nums[i] == num2) c2++;
    }
    if(c1 > nums.size()/3) res.push_back(num1);
    if(c2 > nums.size()/3) res.push_back(num2);

    return res;
}

int main() {
    vector<int> nums = {2,2,1,3};
    auto res = majorityElement(nums);

    for(auto it : res) {
        cout<<it;
    }
}