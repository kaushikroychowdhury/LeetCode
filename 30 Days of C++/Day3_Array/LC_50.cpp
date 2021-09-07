// Pow(x, n)

#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    long long nn = n;
    double ans = 1.0;

    if(nn < 0) nn = -1*nn;

    while(nn) {
        if(nn % 2) {
            nn = nn-1;
            ans = ans * x;
        }
        else {
            nn = nn/2;
            x = x*x;
        }
    }
    if(n<0) return (double)(1)/ans;
    return ans;
}


int main() {
    cout<<myPow(2,-10);
}