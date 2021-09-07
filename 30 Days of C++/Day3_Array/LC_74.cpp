// Search a 2D Matrix | Leetcode
// Search in a rowwiseand column wise sorted matrix | GFG

/* Optimal Approach :
1. Traverse from thr top Back in the row
2. if (target < element) then MOVE LEFT
3. if (target > element) thrn MOVE DOWN
4. if (target == element) then FOUND
5 IF POINTER IS OUT OF BOUND then NOT FOUND*/

#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i = 0, j = matrix[i].size() - 1;
    while(i < matrix.size() && j >= 0) {
        if(target == matrix[i][j]) return true;
        if (target < matrix[i][j]) j--;
        if(target > matrix[i][j]) i++;
    }
    return false;
}

// bool binarySearch(vector<int>& nums, int target, int low, int high) {
//     while (high >= low)
//     {
//         int mid = low + (high-low)/2;
//         if(nums[mid] == target) return true;

//         if(nums[mid] < target) binarySearch(nums, target, mid+1, high);
//         if(nums[mid] > target) binarySearch(nums, target, low, mid-1);
//     }
//     return false;
// }

// bool searchMatrixBinary(vector<vector<int>>& matrix, int target) {
//     int i = 0, j = 0;
//     for (i = 0; i < matrix.size(); i++)
//     {
//         if(matrix[i][j] > target) 
//         {
//             break;
//         }
//     }
//     int row = i-1;
//     // return binarySearch(matrix[row], target, 0, matrix[row].size()-1);
//     return binary_search(matrix[row].begin(), matrix[row].end(), target);
// }

int main() {
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };


    cout<<searchMatrix(matrix, 16)<<endl;
    cout<<searchMatrix(matrix, 13);
}