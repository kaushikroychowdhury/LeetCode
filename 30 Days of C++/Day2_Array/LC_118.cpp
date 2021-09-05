// Pascal's Triangle
// IMPLEMENTATION PROBLEM
/* There are 3 types of Problem can be asked in Interview regarding pascal's tri
1. print the whole Pascal's triangle upto a certain coloumn
 time and space Complexity    O(n^2)

2. Print the nth row for the pascal's triangle
 time and space Complexity      O(n)
 example : r=5
    result = [(1), (4C1), (4C2), (4C3), (1)]

nCr = (n!) / (r! * (n-r)!)

3. Print the rth and cth element of Pascal's triangle
Time Complexity     O(n)
space Complexity    O(1)

Formula is (r-1)C(c-1)
r=5, c=3        result = (4*3)/(2*1)
*/


#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    return (n==0) || (n==1) ? 1 : n* fact(n-1);
}
int Pascal3(int r, int c) {
    if(c == r) return 1;
    return fact(r-1) / (fact(c-1) * (fact((r-1) - (c-1))));
}

vector<int> Pascal2(int r) {
    vector<int> result;
    int c;
    for (int i = 0; i <= r-1; i++)
    {
        if(i == r-1 || i == 0) result.push_back(1);
        else {
            c=fact(r-1) / (fact(i) * (fact((r-1) - (i))));
            result.push_back(c);
        }
    }

    return result;
}

int main() {
    // cout<<Pascal3(5,2);      // pascal prob type 3

    /*                  pascal problem type 2
    vector<int> result;
    result = Pascal2(5);

    for( auto it : result) {
        cout<<it<<", ";
    }
    */

    
}