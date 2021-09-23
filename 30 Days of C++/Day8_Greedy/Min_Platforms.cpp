// Minimum Platforms | GFG

#include<bits/stdc++.h>
using namespace std;

int minPlatforms(int start[], int dep[], int n) {
    int platform = 0, result = 0;

    sort(start, start+n);
    sort(dep, dep+n);

    int s=0, d=0;
    while(s < n) {
        if(start[s] <= dep[d]) {
            platform += 1;
            s++;
            result = max(platform, result);
        }
        else {
            platform -= 1;
            d++;
        }
    }
    return result;
}

int main() {
    int s[] = {900, 940, 950, 1100, 1500, 1800};
    int d[] = {910, 1200, 1120, 1130, 1900, 2000};

    cout<<minPlatforms(s,d,6);
}