// Palindrome Linked List | Adobe Snapdeal Amazon

/*Brute-force Approach : [HASHING]
1. Store all the node's value in a vector
2. Then Check either the vector is palindromic or not

Time Complexity : O(n) + O(n)
Space Complexity : O(n)*/

/*OPTIMAL APPROACH :
1. Find the Middle of the linked list
2. Reverse the RIGHT HALF of the list
3. Point a dummy Pointer to head of List
4. Then Check RIGHT half and LEFT half of the list

Time Complexity : 
Space Complexity : O(1)*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {

    if(head == NULL || head->next == NULL) return true;

    // Middle of list

    ListNode *mid = head;
    ListNode *fast = head;

    while(fast->next != NULL && fast->next->next != NULL) {
        mid = mid->next;
        fast = (fast->next)->next;
    }

    // Reversing the Right Half of the list

    ListNode *d = NULL;
    ListNode *h = mid->next;
    ListNode *nex;

    while(h != NULL) {
        nex = h->next;
        h->next = d;
        d=h;
        h=nex;
    }
    mid->next = d;

    //Check Right Half and Left Half

    h = head;
    while(d != NULL) {
        if(d->val != h->val) {
            return false;
        }
        h=h->next;
        d=d->next;
    }
    return true;
}