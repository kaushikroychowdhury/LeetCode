// Longest Substring Without repeating Characters

/*Brute-force Approach : 
1. Find all the substring 
2. Among all the Substrings Find Substrings without repeating Characters
3. Return the LARGEST length SubString Among Them

Time Complexity : O(n^3)
Space Complexity : O(n) HASHMAP or FREQUENCY ARRAY*/

/* Better Approach : [2 Pointers, Hashing, Sliding Window]

Time Complexity : O(n) + O(n)   ie[O(2n)] for l pointer And r pointer
Space Complexity: O(n)*/

#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int l=0, r=0, length=0;
    set<char> hashSet;

    while(r < s.size()) {
        while(hashSet.count(s[r])) {
            hashSet.erase(s[l]);
            l++;
        }
        hashSet.insert(s[r]);
        length = max(length, (r-l)+1);
        r++;
    }
    return length;
}

/* Optimal Solution [optimization of better approach]
The Problem with Better Approach is, l in moving one by one, what if we can make l
directly jum its perfect position

we can use MAP instead of SET and store <character, index>

Time Complexity : O(n)
Space Complexity : O(n)*/

int lengthOfLongestSubstringOPTIMAL(string s) {
    map<char, int> hashMap;
    int l=0, r=0, length=0;

    while(r < s.size()) {
        if(hashMap.find(s[r]) != hashMap.end()) {
            if(hashMap[s[r]] <= r && hashMap[s[r]] >= l)
                l = hashMap[s[r]] + 1;
            // hashMap[s[r]] = r;
        }
        hashMap[s[r]] = r;
        length = max(length, (r-l)+1);
        r++;
    }
    return length;
}

int main() {
    string s = "b";
    cout<<lengthOfLongestSubstringOPTIMAL(s);

}