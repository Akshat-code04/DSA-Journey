/***
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* kReverse(Node* head, int k) {
    // Write your code here.


    // base case 
    if(head == NULL){
        return NULL;
    }
    // check if k nodes available or not
    Node* temp = head;
    int len = 0;

    while(temp != NULL && len < k){
        temp = temp->next;
        len++;
    }

    if(len < k){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    int count = 0;

    // step 1: reverse the list from k steps 
    while( curr != NULL && count < k ){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // step 2: recursive case for remaining parts 
    if( forward != NULL){
        head -> next = kReverse(forward,k);
    }
    return prev;
}
