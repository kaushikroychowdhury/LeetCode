// Merge two sorted Linked List | Microsoft Yahoo Amazon | Leetcode Easy

/* Brute-Force Approach : 
1. Take a dummy ListNode [head of dummy list]
2. Compare two Sorted list And Add it to the dummy list.
3. return Head Of Dummy List

Time Complexity : O(n+m)
Space Complexity : O(n+m)*/

/*Optimal Approach : [In-Place]
1. */

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *d = new ListNode();
    ListNode *head = d;

    while(l1 != NULL && l2 != NULL) {
        if(l1->val < l2->val) {
            d->next = l1;
            l1 = l1->next;
        }
        else if(l2->val < l1->val) {
            d->next = l2;
            l2 = l2->next;
        }
        else {
            d->next = l1;
            l1 = l1->next;

            d = d->next;

            d->next = l2;
            l2 = l2->next;
        }
        d = d->next;
    }

    // Remaining l1 Elements
    if(l2 == NULL) {
            while(l1 != NULL) {
            d->next = l1;
            l1 = l1->next;
            d = d->next;
        }
    }

    // Remaing l2 Elements
    if(l1 == NULL) {
        while(l2 != NULL) {
            d->next = l2;
            l2 = l2->next;
            d = d->next;
        }
    }

    return head->next; // because the first element is 0. ListNode Constructor assigns val=0
}
