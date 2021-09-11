// Middle of Linked list | LeetCode | Amazon, Microsoft

/* Brute-Force Approach :
1. Count the total number of Nodes In Linked List 
2. find n/2, if n is Odd then middle = (n/2)+1
    if n is even then middle = (n/2)+2
3. traverse to the middle and return the middle element.

Time Complexity : O(n) + O(n/2)
Space Complexity : O(1)*/

/*Optimal Approach : [TORTOISE METHOD, 2 pointer]
1. Assign two Pointers or tortoise to the head of the linked list
2. t1 (Slow) will move one step at an iteration.
3. t2 (Fast) will move two step atan iteration.
4. when t2 is in the last of the Linked List, return t1

Time Complexity : O(n/2)
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

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = (fast->next)->next;
    }
    return slow;
}