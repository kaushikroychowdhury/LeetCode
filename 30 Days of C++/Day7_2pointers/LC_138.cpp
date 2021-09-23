// Copy List with Random Pointer

/*Brute-force approach : [HASHING]
1. Createa hashmap<Node*, Node*>
2. Iterate through the list
    a. Create a copy node of i
    b. store in hashmap <i, copyNode>

3. Iterate through the list
    a. Node *n = i->next
    b. Node * r = i->random
    c. Hashmap[i]->next = hashmap[n]
    d. Hashmap[i]->random = hashmap[r]

4. return hasmap[head]

Time and space Complexity: O(n)*/


/*OPtimal Approach : [WITHOUT HASHING]

time Complexity : O(n)
space Complexity : O(1)*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

Node* copyRandomList(Node* head) {

    if(head == nullptr) return nullptr;

    Node *i = head;
    Node *front;

    while(i != nullptr) {
        front = i->next;
        Node *copy = new Node(i->val);
        i->next = copy;
        copy->next = front;
        i = front;
    }

    Node *i = head;

    while(i != nullptr) {

        if(i->random == nullptr) {
            (i->next)->random = nullptr;
        }
        else {
            (i->next)->random = (i->random)->next;
        }
        i = (i->next)->next;
    }

    Node *i = head;
    Node *copyHead = head->next;
    Node *front;

    while(i != nullptr) {
        front = (i->next)->next;

        if(front == nullptr) {
            i->next = nullptr;
            break;
        }

        (i->next)->next = front->next;
        i->next = front;
        i = front;
    }

    return copyHead;
}