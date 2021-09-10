// Longest Cosequtive Sequence

/* Brute-force Approach :
1. Sort the Array
2. lineraly traverse the Array and find the consequtive sequence
    max = max(max,seq.length)
3. return max

Tilem Complexity : O(nlogn) + O(n)
Space Complexity : O(n)*/

/* OPTIMAL Solution :

Time and Space Complexity : O(n)*/

#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    set<int> hashset;
    int maximum=0;

    for(int i : nums) hashset.insert(i);

    for(int it : nums) {
        if(!hashset.count(it-1)) {
            int current_num = it;
            int count = 1;

            while(hashset.count(current_num+1)) {
                count++;
                current_num += 1;
            }
            maximum = max(maximum,count);
        }
    }
    return maximum;
}

int main() {
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout<<longestConsecutive(nums);
}