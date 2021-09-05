// Set Matrix Zeroes

/*Bruteforce Approach :
1. Traverse through the matrix
    when find 0, inverse its cols' and rows' elements to -1
2. Traverse through the matrix
    Change every -1 to 0

Time Complexity : O(n*m) * O(n+m)
Space Complexity : O(1)*/

/* Better Approach :
Hashing Technique 
1   Declare two Arrays, Cols[] and Rows[]
2.  Traverse through the matrix
        when find 0, Convert that index of col[] and row[] to 0
3. if rows[] == 0 or Cols[] == 0
        convert the entire row and col to zero
        
Time Complexity : O(n*m + n*m)
Space Complexity : O(n) + O(m)*/

/*Optimizing the Better Approach
1. Take a variable Col = true
2. Traverse through the array
        if find a zero at 0th row, then col = false
        else if find zero change that 0th row and col to 0
        
3. Traverse the matrix backwards
        if 0th row or col contains 0, then convert that entire row or col to zero.
        
Time Colplexity : 2*(n*m)
Space Complexity : O(1)*/

#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    bool col0 = true;
    int rows = matrix.size(), cols = matrix[0].size();
    for (int i = 0; i < rows; i++)
    {
        if(matrix[i][0] == 0) col0 = false;
        for (int j = 0; j < cols; j++)
        {
            if(matrix[i][j] == 0) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for (int i = rows-1; i >= 0; i--)
    {
        for (int j = cols; j >= 0; j--)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (col0 == false) matrix[0][0] = 0;
}

int main() {
    // vector<vector<int>> matrix = {
    //     {1,1,1},
    //     {1,0,1},
    //     {1,1,1}
    // };

    vector<vector<int>> matrix = {
    {0,1,2,0},
    {3,4,5,2},
    {1,3,1,5}
    };
    setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}