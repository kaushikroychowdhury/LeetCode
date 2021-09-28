// Fractional Knapsack | GFG

// Time Complexity : O(nlogn) + O(n)
// Space Complexity : O(n)

#include<bits/stdc++.h>
using namespace std;

struct items {
    int value;
    int weight;
    int vpw;
};

bool comparator(struct items i1, items i2) {
    return (i1.vpw > i2.vpw);
}

void fracKnapsack(int values[], int weights[], int n, int c) {
    struct items item[n];
    for(int i=0; i<n; i++) {
        item[i].value = values[i];
        item[i].weight = weights[i];
        item[i].vpw = values[i]/weights[i];
    }

    sort(item, item+n, comparator);

    int i = 0, profit = 0;
    while(c > 0 && i < n) {
        if(item[i].weight <= c) {
            c -= item[i].weight;
            profit += item[i].value;
        }
        else {
            profit += (item[i].vpw*c);
            c = 0;
        }
        i++;
    }

    cout<<"Profit is = "<<profit;
}

int main() {
    int n,c;
    cout<<"Number of Items"<<endl;
    cin>>n;
    cout<<"Capacity of Knapsack"<<endl;
    cin>>c;
    int values[n], weights[n];

    cout<<"Values"<<endl;
    for(int i=0; i<n; i++) {
        cin>>values[i];
    }
    cout<<"Weights"<<endl;
    for(int i=0; i<n; i++) {
        cin>>weights[i];
    }

    fracKnapsack(values, weights, n, c);
}