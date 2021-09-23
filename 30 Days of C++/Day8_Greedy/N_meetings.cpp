// N Meetings in one Room

#include<bits/stdc++.h>
using namespace std;

struct meeting {
    int start;
    int end;
    int pos;
};

bool comparator(struct meeting m1, meeting m2) {
    if(m1.end > m2.end) return false;
    else if(m1.end < m2.end) return true;
    else if(m1.pos < m2.pos) return true;
    return false;
}

void nmeetings(int s[], int e[], int n) {
    struct meeting meet[n];

    for(int i=0; i<n; i++) {
        meet[i].start = s[i];
        meet[i].end = e[i];
        meet[i].pos = i+1;
    }

    sort(meet, meet+n, comparator);

    vector<int> answer;
    int limit = meet[0].end;
    answer.push_back(meet[0].pos);

    for(int i=0; i<n; i++) {
        if(meet[i].start > limit) {
            limit = meet[i].end;
            answer.push_back(meet[i].pos);
        }
    }

    for(int i=0; i<answer.size(); i++) {
        cout<<answer[i]<<" ";
    }
}

int main() {
    int s[] = {1,3,0,5,8,5};
    int e[] = {2,4,6,7,9,9};
    nmeetings(s, e, 6);
}