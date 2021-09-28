// Greedy Algorithm to find minimum number of coins | GFG

#include<bits/stdc++.h>
using namespace std;

void minCoins(int v) {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000}, counter=0, i=0;
    while (v > 0) {
        i=0;
        while(coins[i] <= v && i < 9) {
            i++;
        }
        if(v == coins[i]) {
            v = 0;
            counter++;
        }
        else {
            v = v-coins[i-1];
            counter++;
        }
    }
    cout<<counter;
}

int main() {
    int v;
    cout<<"value"<<endl;
    cin>>v;

    minCoins(v);
}