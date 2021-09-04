// Merge Sorted Array | LeetCode
// Merge Sorted array in O(1) Space | GFG     (no extra space)

/* Naive approach
1. Append the second Array to the first Array
2. Sort the first array

Space Complexity => O(1)

OR

1. Append First and Second Array into the third array
2. Sort the array
3. take the first n1(size of first array) elements and put it into First array
4. take thelast last n2(size of second array) elements and put it into Second array

Time Complexity => O(nlogn) + O(n) +O(n)    Sort + Take array elements + put array elements
Space Complexity => O(n)    For third array*/

/* optimal Solution 1
1. set a pointer to first element of first array
2. Traverse through first array

Example :       a1[] = 1  4  7  8  10
                a2[] = 2  3  9
                
                p=1 < 2     do nothing
                p=4 > 2     swap(2,4),  Sort(a2)
                1  2  7  8  10
                3  4  9
                
                p=7 > 3     swap(3,7),  Sort(a2)
                1  2  3  8  10
                4  7  9
                
                p=8 > 4     swap(4,8),  Sort(a2)
                1  2  3  4  10
                7  8  9
                
                p=10 > 7    swap(7,10),  Sort(a2)
                a1[] = 1  2  3  4  7
                a2[] = 8  9  10
                
Time Complexity     O(n+m)      n : p to traversing first array
                                m : Insertion Sort or Reorder*/

// Optimal Solution 2       GAP method

#include<bits/stdc++.h>
using namespace std;

int next_gap(int gap) {
    if(gap <= 1) return 0;
    return ceil(gap/2);
}

void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
    int i, j, gap = n+m;
    for(gap = next_gap(gap); gap > 0; gap = next_gap(gap))
    {
        //compairing in first array
        for (i = 0; i+gap < n; i++)
        {
            if(nums1[i] > nums1[i+gap])
                swap(nums1[i], nums1[i+gap]);
        }
        
        //compairing in second array
        for(j = gap>n ? gap-n : 0; i<n && j<m; i++, j++) {
            if(nums1[i] > nums2[j])
                swap(nums1[i], nums2[j]);
        }

        if(j<m) {
            // compairing second array
            for (j = 0; j+gap < m; j++)
            {
                if(nums2[j] > nums2[j+gap])
                    swap(nums2[j], nums2[j+gap]);
            }
        }
    }

}

int main() {
    vector<int> nums1 = {1,4,7,8,10};
    vector<int> nums2 = {2,3,9};

    merge(nums1, nums1.size(), nums2, nums2.size());

    for(auto i : nums1) cout<<i<<" ";
    cout<<endl;
    for(auto i : nums2) cout<<i<<" ";
}