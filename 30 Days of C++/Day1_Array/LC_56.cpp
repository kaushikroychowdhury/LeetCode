// Merge Intervals | leetCode

// Optimal Solution

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    vector<int> temp = intervals[0];

    for (int i = 1; i < intervals.size(); i++)
    {
        if(intervals[i][0] >= temp[0] && intervals[i][0] <= temp[1]) {
            temp[1] = max(temp[1], intervals[i][1]);
        }
        else {
            result.push_back(temp);
            temp = intervals[i];
        }
    }
    result.push_back(temp);
    return result;
}

int main () {
    vector<vector<int>> intervals = {
        {1,3}, {2,6}, {8,10}, {15,18}
    };
    auto result = merge(intervals);

    for (int i = 0; i < result.size(); i++)
    {
        cout<<'(';
        for (int j = 0; j < 2; j++)
        {
            cout<<result[i][j]<<',';
        }
        cout<<')'<<endl;
    }

}