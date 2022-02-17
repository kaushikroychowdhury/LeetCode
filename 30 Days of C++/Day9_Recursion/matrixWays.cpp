// Find the number of ways from top-left corner to bottom-right corner of a 2D matrix.

#include<bits/stdc++.h>
using namespace std;

int findWays(int n, int m) {
    if(n==1 || m==1) {
        return 1;
    }

    return findWays(n-1,m) + findWays(n,m-1);
}


// Problem in passing 2d array in a function
// int findWaysDP(int n, int m, int ways[][]) {
//     if(ways[n][m] != 0) {
//         return ways[n][m];
//     }

//     int a = findWaysDP(n-1,m,ways) + findWaysDP(n,m-1,ways);
//     ways[n][m] = a;
//     return a;
// }

int main() {
    cout<<findWays(4,2);
    // int n=4,m=3;
    // int waysTable[n+1][m+1];

    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=m; j++) {
    //         if(i==1 || j==1) {
    //             waysTable[i][j] = 1;
    //         }
    //         else {
    //             waysTable[i][j] = 0;
    //         }
    //     }
    // }

    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=m; j++) {
    //         cout<<waysTable[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<findWaysDP(n,m,waysTable);


}