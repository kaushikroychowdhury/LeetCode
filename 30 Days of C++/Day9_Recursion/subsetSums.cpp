// Subset Sums | GFG

/* Brute Force Approch : Powerset Algorithm
FInd All the subsets and add them.

Time Complexity : O(2^n)*/

/* Optimal Approach : Rucursion

Time Complexity : O(2^n + 2^N log 2^n)*/

#include<bits/stdc++.h>
using namespace std;

void subsetSums(vector<int> &set, int index, int n, int s, vector<int> &res) {
    // Base Case
    if(index == n) {
        res.push_back(s);
        return;
    }

    subsetSums(set, index+1, n, s+set[index], res);
    subsetSums(set, index+1, n, s, res);
}

int main() {
    vector<int> set = {3,1,2};
    vector<int> res;

    subsetSums(set, 0, 3, 0, res);

    sort(res.begin(), res.end());

    for(int i=0; i<pow(2,3); i++) {
        cout<<res[i]<<"  ";
    }
}