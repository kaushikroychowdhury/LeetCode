// Intersection of two linked list | Amazon Microsoft | LeetCode easy

/* Brute-force Approach :

THERE ARE TWO LISTS A and B.
1. Point a pointer in any list (lets take B)
2. Check wheather the address of that node is similar to any of the A's Node's address
3. IF we find a similar one then RETURN that Node's Address
4. ELSE RETURN NULL.

Time Complexity : O(n^2)*/

/*Better Apprach : [ HASHING ]
1. First traverse through any list and hash all the node's address in a HASHED ARRAY
2. Traverse through the other list and check wheather we got any similar address
3. IF we find a similar one then RETURN that Node's Address
4. ELSE RETURN NULL.

Time Complexity : O(n) + O(m)
Space Complexity : O(n) HASHED ARRAY*/

/*OPTIMAL APPROACH 1 :
1. Find the length of both the LISTS
2. diff = A_length - B_length
3. Traverse the longest list upto 'diff'
    now d1 and d2 are in same level

4. Traverse both the pointers (d1, d2) SIMULTANEOUSLY
IF d1 == d2, RETURN address of d1
ELSE RETURN NULL

Time Complexity : O(2m)

NOTE: Code is lengthy*/

/*OPTIMAL APPROACH 2 :
1. point d1 = head(A)
2. point d2 = head(B)
3. Traverse both the pointers until d1 or d2 is NULL
    IF d1 == NULL, then d1 = head(B)
    IF d2 == NULL, then d2 = head(A)
now d1 and d2 are in same level

4. Traverse both the pointers (d1, d2) SIMULTANEOUSLY
IF d1 == d2, RETURN address of d1
ELSE RETURN NULL

Time Complexity : O(2m)*/

#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

// OPTIMAL APPROACH 2
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *d1 = headA;
    ListNode *d2 = headB;

    if(d1 == NULL || d2 == NULL) return NULL;

    while(d1 != d2) {
        if(d1 == NULL) {
            d1 = headB;
        }

        if(d2 == NULL) {
            d2 = headA;
        }

        d1 = d1->next;
        d2 = d2->next;
    }
        return d1;
}
// OPTIMAL APPROACH 1
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // Finding Length of the lists
    int A_len = 0, B_len = 0;
    ListNode *d = headA;

    while(d != NULL) {
        A_len++;
        d = d->next;
    }
    d = headB;
    while(d != NULL) {
        B_len++;
        d = d->next;
    }
    int diff = abs(A_len - B_len);

    ListNode *a = headA;
    ListNode *b = headB;

    if(A_len > B_len) {
        for(int i=0; i<diff; i++) {
            a = a->next;
        }
    }
    if(A_len < B_len) {
        for(int i=0; i<diff; i++) {
            b = b->next;
        }
    }

    while(a != b) {
        a = a->next;
        b = b->next;
    }
    if(a == b) {
        return a;
    }
    return NULL;
}