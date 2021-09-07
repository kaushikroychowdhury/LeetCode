// Best time to buy and sell stock |Leetcode
// Stock Buy Sell to Maximize Profit | GFG

/* Naive Approach : 
1. Compare each day with all, then find the maximum profit
Time Complexity = O(n^2)*/

/* Optimal Approach
1. Take oth index as min and p = 0 initially
2. traverse through the array,
        if find minimum value than min, then change the value of min with it
        find the profit,
        if the profit is greater than the value of p, then change the value of p with it
        
Time Comlexity : O(n)*/

#include<bits/stdc++.h>
using namespace std;

vector<int> maxProfit(vector<int>& prices) {
    int min = prices[0], profit = 0, buy = 0, sell = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < min)
        {
            min = prices[i];
            buy = i;
        }
        else if (prices[i] - min > profit)
        {
            profit = prices[i] - min;
            sell = i;
        }
    }
    return {profit, buy, sell};
}

int main() {
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    vector<int> res = maxProfit(prices);
    cout<<res[0]<<endl;

    cout<<"Buy on day : "<<res[1]+1<<endl;
    cout<<"Sell on day : "<<res[2]+1;
}