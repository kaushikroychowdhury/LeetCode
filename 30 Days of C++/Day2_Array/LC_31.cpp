// Next Permutation

/*Bruteforce Approach

1. Find all the permutation of that sequence
2. Search for the permutation that is given, then rturn the next one
3. if the given sequence is the last permutation, then return the first one*/

/*Optimal Approach

1. traverse the array from backwards
    find the index where a[i] < a[i+1], say it as index1
2. Again Traverse Backwards
    find the index where a[index1] < a[i], say it aa index2
3. swap(a[index1], a[index2]
4. reverse(index1 + 1, last)

Note: when ever we cant find index1 then return reverse of the sequence

Time Complexity : O(n) + O(n) + O(n)
Space Complexity : O(1)*/

#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int index1 = -1, index2 = -1;
    for (int i = nums.size()-2; i >= 0; i--)
    {
        if (nums[i] < nums[i+1])
        {
            index1 = i;
            break;
        }
    }
    if (index1 < 0)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = nums.size()-1; i > index1; i--)
    {
        if (nums[index1] < nums[i])
        {
            index2 = i;
            break;
        }
    }
    swap(nums[index1], nums[index2]);
    reverse(nums.begin() + index1 + 1, nums.end());
}

int main() {
    vector<int> nums ={1,2,3};

    cout<<endl;
    nextPermutation(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<", ";
    }
}
