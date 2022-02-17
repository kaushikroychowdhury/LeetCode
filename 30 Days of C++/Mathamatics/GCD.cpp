// Greatest common Factor of two numbers

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(a%b == 0) {
        return b;
    }

    gcd(b, a%b);
}

// GCD of an array
int gcdArray(int arr[], int n) {
    int result = arr[0];
    for(int i=1; i<n; i++) {
        result = gcd(arr[i], result);

        if(result == 1)
            return 1;
    }
    return result;
}

// Recursive Approach for GCD of an Array
int gcdArrayRecursive(vector<int>& arr, int idx) {
    if (idx == arr.size() - 1) {
        return arr[idx];
    }
    int a = arr[idx];
    int b = gcdArrayRecursive(arr, idx + 1);
    return __gcd(
        a, b);
}

int main() {
    cout<<gcd(48,72);
    cout<<__gcd(48,72);         // prebuilt function for finding GCD

    int arr[] = { 2, 4, 6, 8, 16 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<gcdArray(arr, n);

    vector<int> a = {2,4,6,8,16};
    cout<<gcdArrayRecursive(a,0);
}