// Find the Duplicate number

/*Naive Approach :
1. Sort the array
2. traverse through the array, whenever we find A[i] == A[i+1], That
   number is the duplicate number*/

/*Better Approach       [Hashing Technnique]
1. traverse the vector    O(n)
2. store the occurrences in another array (hashing Technique)

Example :  nums = {4, 3, 6, 2, 1, 1}
Hashed Array = {0,2,1,1,1,0,1}

Value at index 1 is greater than 1, hence duplicate number is 1*/

/*Optimal Approach
Detect the Cycle in linked list      [Tortoise method]
1. S=F=0    Slow pointer have 1 move and fast pointer have 2 moves
2. In second iteration,
   F=0     Slow and fast pointer have 1 move
    
    when Slow == fast, that is the duplicate number*/

#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];

    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {
    vector<int> nums = {3,1,3,4,2};
    cout<<findDuplicate(nums);
}