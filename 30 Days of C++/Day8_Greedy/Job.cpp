// Job Sequencing | GFG

#include<bits/stdc++.h>
using namespace std;

struct JOB {
    int id;
    int deadline;
    int profit;
};

bool comparator(struct JOB j1, JOB j2) {
    if(j1.profit > j2.profit) return true;
    return false;
}

auto jobSequencing(int id[], int deadline[], int profit[], int n) {
    struct JOB job[n];

    for(int i=0; i<n; i++) {
        job[i].id = id[i];
        job[i].deadline = deadline[i];
        job[i].profit = profit[i];
    }
    
    for (int i = 0; i < 4; i++)
    {
        cout<<job[i].id<<"  "<<job[i].deadline<<"  "<<job[i].profit<<endl;
    }
    cout<<" ---------------------- "<<endl;
    sort(job, job+n, comparator);

    for (int i = 0; i < 4; i++)
    {
        cout<<job[i].id<<"  "<<job[i].deadline<<"  "<<job[i].profit<<endl;
    }

    int *s = max_element(deadline, deadline + n);
    int size = int(*s);
    cout<<int(*s)<<endl;
    vector<int> result(size+1,-1);

    for(auto i : result) {
        cout<<i<<" "<<endl;
    }

    result[job[0].deadline] = job[0].id;
    int p = job[0].profit;

    cout<<p<<endl;
    cout<<result[job[0].deadline]<<endl;

    for(int i=1; i <= size; i++) {
        if(result[job[i].deadline] == -1) {
            result[job[i].deadline] = job[i].id;
            p += job[i].profit;
            cout<<p<<endl;
        }
        else {
            int c = job[i].deadline - 1;
            while(c >= 1) {
                if(result[c] == -1) {
                    result[c] = job[i].id;
                    p += job[i].profit;
                    break;
                }
                c--;
            }
        }
    }

    return result;

}
int main() {
    int id[] = {1,2,3,4};
    int deadline[] = {4,1,1,1};
    int profit[] = {20,10,40,30};

    auto res = jobSequencing(id, deadline, profit, 4);

    for(auto i : res) {
        cout<<i<<" ";
    }
}