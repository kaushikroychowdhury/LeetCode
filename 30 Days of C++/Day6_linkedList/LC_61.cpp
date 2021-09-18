// Rotate List | Adobe Amazon Microsoft GS MMT

/*Brute-force Approach :
1. Loop until k (k is number of rotation)
2. Find the Last node of the list
3. point last node's next to head of the list
4. Make the last node as head
5. point second last node's next to NULL

Time Complexity : O(k*n) *n because we need to find the last node k times*/

/*Optimal Approach :

As we can see if k is multiple of length of list then the list remains same
1. k = k % len
2. same as brute force approach

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

ListNode* rotateRight(ListNode* head, int k) {

    if(head == NULL || head->next == NULL) return head;

    int length=0;
    ListNode *t = head;
    ListNode *last = head->next;
    ListNode * secLast = head;

    while(t != NULL) {
        length++;
        t = t->next;
    }

    k = k % length;

    for(int i=0; i<k; i++) {

        while(secLast->next->next != NULL) {
            last = last->next;
            secLast = secLast->next;
        }

        last->next = head;
        head = last;
        secLast->next = NULL;

        last = head->next;
        secLast = head;
    }

    return head;
}