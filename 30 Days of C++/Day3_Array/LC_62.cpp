// Unique Paths | Google Interview Question | LeetCode

/* Brute-force Approach : (RECURSIVE SOLUTION)
1. BASE CASE :
    a. if(i >= Row Size  OR  j >= Column Size) RETURN 0
    b. if(i == Row Size - 1  AND  j == Column Size - 1) Return 1

2. RETURN DownPath + RightPath

Time and Space Complexity : Exponential*/

#include<bits/stdc++.h>
using namespace std;

int uniquePathsBrute(int i, int j, int n, int m) {
    if(i>=n || j>=m) return 0;
    if(i==n-1 && j==m-1) return 1;
    else {
        return uniquePathsBrute(i+1, j, n, m) + uniquePathsBrute(i, j+1, n, m);
    }
}

/* Better Approach : (Optimizing Brute-force Approach using DYNAMIC PROGRAMMING)
1. Cache the results in every recursive call to reduce the same state recursive calls
2. to convert a recursive Solution to Dynamic programming solution :
    a. when we return the answer, chache it in DP structure
    b. after every recursive call, check either the result of that state is already
       in DP structure or not.

Time Complexity : O(n*m)
Space Complexity : O(n*m)*/

int uniquePathsBetter(int i, int j, int n, int m, vector<vector<int>>& dp) {
    if(i>=n || j>=m) return 0;
    if(i==n-1 && j==m-1) return 1;

    if(dp[i][j] != -1) return dp[i][j];
    else {
        return dp[i][j] = uniquePathsBetter(i+1, j, n, m, dp) +
                            uniquePathsBetter(i, j+1, n, m, dp);
    }
}

/* Optimal Approach : (Combinatorics Approach)
1. Total_steps = (column_size-1) + (row_size-1)
               = column_size + row_size - 2

2. Right move = column_size-1
    Down move = row_size-1

3. return total_steps C right_move      OR      total_steps C down_move

Time Complexity: O(column_size-1) OR O(row_size-1)
Space complexity : O(1)*/

int uniquePathsOptimal(int n, int m) {      // LEETCODE SOLUTION
    int total_steps = m+n-2;
    int right_move = m-1;
    double result = 1;

    for (int i = 1; i <= right_move; i++)
    {
        result = result * (total_steps - right_move + i)/i;
    }
    return result;
}

int main() {

    /* FILL THE VECTOR WITH SPECIFIC VALUE
    vector<vector<int>> VECTOR_NAME(
    ROW_COUNT,
    vector<int>(COLUMN_COUNT, SPECIFIC_VALUE));
    */

    vector<vector<int>> dp(7, vector<int>(3,-1));

    cout<<"Brute-force : "<<uniquePathsBrute(0,0,7,3)<<endl;
    cout<<"Better : "<<uniquePathsBetter(0,0,7,3,dp)<<endl;
    cout<<"Optimal : "<<uniquePathsOptimal(7,3);
}