// Linked List Cycle | LeetCode Easy | Amazon Samsung Microsoft

/* Brute-force Approach : [HASHING]
1. Traverse Through the list while( pointer != NULL)
2. Check if the address of node is in HASHMAP
        return TRUE
    else
        Store the Node's Adress in HASHMAP
3. Return FALSE {Contains NO CYCLE}

Time and space Complexity : O(n)*/

/* OPTIMAL APPROACH : [2 Pointers OR tortoise method]
1. Slow = fast = head {slow moves 1 step while fast moves 2 steps}
2. Iterate until slow == fast

3. If slow == fast, then RETURN TRUE
4. Else RETURN FALSE

Time Complexity : O(n)
Space Complexity : O(1)*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {

    if(head == NULL || head->next == NULL){
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = slow->next;

    while(slow != fast) {
        if(fast == NULL || fast->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}