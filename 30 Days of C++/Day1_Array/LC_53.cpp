// Maximum Subarray Kadane's Algorithm

#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int maximum = INT_MIN;

    for (auto it : nums) {
        sum += it;
        maximum = max(maximum, sum);
        if(sum<0) sum = 0;
    }

    return maximum;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums);
}