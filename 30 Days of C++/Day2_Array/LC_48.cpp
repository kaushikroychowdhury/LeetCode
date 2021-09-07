// Rotate Image

/*Bruteforce Approach :
1. take a result matrix
2. traverse every row in matrix (FORWARD)
        make first row the last column of result
3.return result*/

/* Optimal Approach : (IN-PLACE)
1. transpose the matrix
2. reverse every row of the transposed matrix*/

#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    // Transpose of the matrix
    for(int i=0; i<matrix.size(); i++) {
        for (int j = i+1; j < matrix[i].size(); j++)
        {
            swap(matrix[j][i], matrix[i][j]);
        }
    }

    // reverse every row of the matrix
    /*
    In 2d vector
    to rotate rows we use -> reverse(a[i].begin,a[i].end());
    to rotate columns we use -> reverse(a.begin(),a.end());
    */

    for(int i=0; i < matrix.size(); i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
vector<vector<int>> matrix = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
};
rotate(matrix);

for(auto i : matrix){
    for(auto j : i) {
        cout<<j<<", ";
    }
    cout<<endl;
}
}