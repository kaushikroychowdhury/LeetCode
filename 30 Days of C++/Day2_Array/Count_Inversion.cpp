// Counting inversions (Using Merge-sort) | GFG

#include<bits/stdc++.h>
using namespace std;

int merge(int nums[], int low, int mid, int high) {
    int i = low, j = mid, k=low, inv_count = 0;
    int a[high+1];
    while(i <= mid-1 && j <= high)
    {
        if(nums[i] > nums[j]) {
            a[k] = nums[j];
            j++;k++;
            inv_count += (mid-i);
        }
        else {
            a[k] = nums[i];
            i++;k++;
        }
    }
    

    while(i<=mid-1) {a[k] = nums[i]; i++;k++;}

    while(j<=high) {a[k] = nums[j]; j++;k++;}

    for (int i = low; i <= high; i++)
    {
        nums[i] = a[i];
    }

    return inv_count;
}

int mergeSort(int nums[], int low, int high) {
    int inv_count = 0;
    if(high > low) {
    int mid = (low + high)/2;

    inv_count += mergeSort(nums, low, mid);
    inv_count += mergeSort(nums, mid+1, high);
    inv_count += merge(nums, low, mid+1, high);
    }

    return inv_count;
}

int main() {
    int nums[] = {8,4,2,1}, n=4;

    //     for(int i=0; i<n; i++) {
    //     cout<<nums[i]<<", ";
    // }
    cout<<endl;

    cout<<mergeSort(nums, 0, n-1);

    // for(int i=0; i<n; i++) {
    //     cout<<nums[i]<<", ";
    // }
}