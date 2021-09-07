// Majority Element I

/**/

#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {        // Moore Voting Algorithm
    int count = 0, element = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            element = nums[i];
            count += 1;
        }
        else if (element == nums[i]) {
            count += 1;
        }
        else {
            count -= 1;
        }
    }
    return element;
}

int main () {
    vector<int> nums = {3,3,4};
    cout<<majorityElement(nums);
}