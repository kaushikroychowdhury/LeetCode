//Max Consecutive ones

#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0, max = 0, n = nums.size();

    for(int i=0; i<n; i++) {
        if(nums[i] == 1) {
            count += 1;
            if(count > max) {
                max = count;
            }
        }
        else {
            count = 0;
        }
    }
    return max;
}
int main() {
    vector<int> nums = {1,1,0,1,1,1};
    cout<<findMaxConsecutiveOnes(nums);
}