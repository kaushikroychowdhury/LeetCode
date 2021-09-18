// Flattening a Linked List | GFG | Amazon Microsoft

/*Time Complexity : O(Summation of List)
Space Complexity : O(1)*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *buttom;
    ListNode() : val(0), next(nullptr), buttom(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), buttom(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeList(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode();
    ListNode *temp = dummy;

    while(l1 != NULL && l2 != NULL) {
        if(l1->val < l2->val) {
            temp->buttom = l1;
            l1 = l1->buttom;
            temp = temp->buttom;
        }
        else if(l1->val > l2->val) {
            temp->buttom = l2;
            l2 = l2->buttom;
            temp = temp->buttom;
        }
        else {
            temp->buttom = l1;
            temp = temp->buttom;
            temp->buttom = l2;
            temp = temp->buttom;
            l1 = l1->buttom;
            l2 = l2->buttom;
        }
    }

    if(l1 == NULL) {
        temp->buttom = l2;
    }
    else {
        temp->buttom = l1;
    }
    return dummy->buttom;
}

ListNode *flatten(ListNode *head) {
    if(head == NULL || head->next == NULL) return head;

    // reccur for the list in right
    head->next = flatten(head->next);

    // now merge
    head = mergeList(head, head->next);

    return head;
}