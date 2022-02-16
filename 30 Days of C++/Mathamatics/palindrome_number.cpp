#include<bits/stdc++.h>
using namespace std;

bool paindrome_number(int n) {
    int temp=n, sum = 0, r;

    while(n>0) {
        r = n%10;
        sum = (sum*10) + r;
        n = n/10;
    }

    if(sum == temp) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    cout<<paindrome_number(1331);
}