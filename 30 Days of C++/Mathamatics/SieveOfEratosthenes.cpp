// Sieve Of Eratosthenes        Find prime numbers in Range

#include<bits/stdc++.h>
using namespace std;

void SOE(int n) {
    vector<bool> res(n+1,true);
    res[1] = false;
    int root = sqrt(n);

    for(int i=2; i<=root; i++) {
        for(int j=2*i; j<=n; j+=i) {
            res[j] = false;
        }
    }

    for(int i=2; i<=n; i++) {
        if(res[i] == true)
            cout<<i<<" , ";
    }
}

int main() {
    int n;
    cin>>n;
    SOE(n);
}