// trapping the Rainwater.

/*Brute-force approach :
Formula : min( max(0 to i), max(i to n-1)) - height[i]
we are finding unit of water can be trapped by i th index.

Time Complexity : O(n^2)  because we are finding leftmax and rightmax for every index.
Space Complexity : O(1)*/

/*Better Approach : [HASHING]


1. For every index store leftmax and rightmax in arrays
2. then using the same formula. we can calculate the result

Time Complexity : O(n)
Space Complexity : O(2n) because of HASHING we need two arrays of size n.*/


/*Optimal Approach : [2-POINTERS]

Time Complexity : O(n)
Space Complexity : O(1)*/

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int left = 0, right = height.size()-1, result = 0;
    int leftmax = 0, rightmax = 0;

    while(left <= right) {

        if(height[left] <= height[right]) {
            if(height[left] >= leftmax) {
                leftmax = height[left];
            }
            else {
                result += leftmax - height[left];
            }
            left++;
        }
        else {
            if(height[right] >= rightmax) {
                rightmax = height[right];
            }
            else {
                result += rightmax - height[right];
            }
            right--;
        }
    }
    return result;
}