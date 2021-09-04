// Sort array

#include<bits/stdc++.h>
using namespace std;

    void sortColors(vector<int>& nums) {
    /* We have to inplace sort      (Counting Sort) Doublr pass
    Count the occurrences  O(n)
    Fill the array   O(n) */

    // Dutch National Flag Algorithm    O(n) Single Pass
    int low = 0, mid = 0, high = nums.size()-1;
    while(mid <= high) {
        if(nums[mid]==0) {
            swap(nums[low], nums[mid]);
            low++; mid++;
        }

        else if(nums[mid]==1) {
            mid++;
        }

        else if(nums[mid]==2) {
            swap(nums[mid], nums[high]);
            high--;
        }
    }

}

int main() {
    vector<int> nums = {2,0,2,1,1,0};
    // vector<int> nums = {2,0,1};
    sortColors(nums);
    for(auto it : nums) {
        cout<<it;
    }
}