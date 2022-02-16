#include<bits/stdc++.h>
using namespace std;

int trail_zero(int n) {
    int res = 0;

    for(int i=5; i<=n; i=i*5) {
        res = res + (n/i);
    }
    return res;
}

int main() {
    cout<<trail_zero(35);
}