// Remove Nth Node Fron End Of List | Amazon Microsoft Adobe | LeetCode

/* Brute-Force Approach :
1. Traversing the list and find out the total number of nodes in the List
2. k = toal_node - n;
3. if n == total nodes, Return head->next
4. go to kth node and delete it.

Time Complexity : O(n) + O(n) [Double Pass]*/

/*OPTIMAL APPROACH : [2 POINTERS, TORTOISE METHOD]

Time Complexity : O(n) [Single Pass]*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *slow = head;
    ListNode *fast = head;

    if(fast->next == NULL) return NULL; //If only one element exist;

    while(n > 0) {
        fast = fast->next;
        n--;
    }

    if(fast == NULL) {
        return head->next;
    }   // IF n == Total_nodes

    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = (slow->next)->next;
    return head;
}