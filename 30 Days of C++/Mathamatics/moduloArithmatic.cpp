#include<bits/stdc++.h>
using namespace std;

int fastPower(int a, int b) {       //Recursive
    if(b==0) {
        return 1;
    }

    if(b%2 == 0) {
        return fastPower(a*a, b/2);
    }
    else {
        return fastPower(a,b-1) * a;
    }
}

int fastPowerI(int a, int b) {          // Iterative
    int res = 1;
    while(b>0) {
        if((b&1) != 0) {
            res = res*a;
        }
        a=a*a;
        b=b>>1;
    }
    return res;
}

int moduloOperation(long a, long b, int n) {
    long res=1;
    while(b>0) {
        if((b&1) != 0) {
            res = ((res%n) * (a%n))%n;
        }
        a = ((a%n) * (a%n))%n;
        b=b>>1;
    }
    return res;
}

int main() {
    cout<<fastPowerI(4,4)<<endl;
    long a = 3978432, b = 5;
    int n = 1000000007;
    cout<<moduloOperation(a, b, n);
}