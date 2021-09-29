// Subsets | LeetCode

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> res = {{}};

void allSubset(vector<int> &set, int index, int n, vector<int> &subSet) {
    // Base Case
    if(index == n) {
        res.push_back(subSet);
        return;
    }

    subSet.push_back(set[index]);
    allSubset(set, index+1, n, subSet);
    subSet.pop_back();
    allSubset(set, index+1, n, subSet);
}

int main() {
    vector<int> set = {3,1,2};
    vector<int> subSet = {};

    allSubset(set, 0, 3, subSet);
    res.pop_back();

    for(auto i : res) {
        cout<<"[ ";
        for(auto j : i) {
            cout<<j<<"  ";
        }
        cout<<"]";
        cout<<endl;
    }
}
