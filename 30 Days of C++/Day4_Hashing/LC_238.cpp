//Product of Array except itself | Preffix Sum | Hashing

#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixProduct(n);
    vector<int> suffixProduct(n);
    vector<int> result(n);

    // Prefix Product
    prefixProduct[0] = nums[0];
    for(int i=1; i<n; i++) {
        prefixProduct[i] = nums[i]*prefixProduct[i-1];
    }

    // Suffix Product
    suffixProduct[n-1] = nums[n-1];
    for(int i=n-2; i>=0; i--) {
        suffixProduct[i] = nums[i]*suffixProduct[i+1];
    }

    // Result
    result[0] = suffixProduct[1];
    result[n-1] = prefixProduct[n-2];
    for(int i = 1; i < n-1; i++)
    {
        result[i] = prefixProduct[i-1] * suffixProduct[i+1];
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,3,4};
    vector<int> result = productExceptSelf(nums);
    for(int i : result) cout<<i<<" ,";
}