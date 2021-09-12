// Add Two Numbers | Amazon Microsoft Qualcomm Facebook | leetcode

/* Brute-force Approach :
1. Convert both the list into Numbers
2. Add both the numbers
3. Convert the result to list. [insertAtTail()]

e.g : 2 -> 4 -> 3 -> NULL
        n1 = 2*1 + 4*10 + 3*100 = 342
      5 -> 6 -> 7 -> 9 -> NULL
        n2 = 5*1 + 6*10 + 7*100 + 9*1000 = 9765

    res = n1 + n2
    insertAtTail(res)

    7 -> 0 -> 1 -> 0 -> 1 -> NULL*/

/* Optimal Approach : */

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *d = new ListNode();
    ListNode *temp = d;
    int c=0, sum=0;

    while(c != 0 || l1 != NULL || l2 != NULL) {

        if(l1 == NULL && l2 != NULL){
            sum = l2->val + c;
            ListNode *t = new ListNode(sum%10);
            c = sum/10;
            temp->next = t;
            l2 = l2->next;
        }

        else if(l2 == NULL && l1 != NULL){
            sum = l1->val + c;
            ListNode *t = new ListNode(sum%10);
            c = sum/10;
            temp->next = t;
            l1 = l1->next;
        }

        else if(l1 == NULL && l2 == NULL) {
            sum = c;
            ListNode *t = new ListNode(sum%10);
            c = sum/10;
            temp->next = t;
        }

        else {
            sum = l1->val + l2->val + c;
            ListNode *t = new ListNode(sum%10);
            c = sum/10;
            temp->next = t;
            l1 = l1->next;
            l2 = l2->next;
        }

        temp = temp->next;
    }

    return d->next;
}