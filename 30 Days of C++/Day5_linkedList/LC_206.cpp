// Reverse a Linked List

/* Objective :
1. link every next node to its previous one
2. return the last element as head

Time Complexity : O(n)*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverseList(ListNode* head) {
    ListNode* d = NULL;
    ListNode* next;
    while(head != NULL) {
        next = head -> next;
        head->next = d;
        d = head;
        head = next;
    }
    return d;
}

int main() {
    
}