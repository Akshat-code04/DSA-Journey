#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
Node<int>* solve(Node<int>* first, Node<int>* second){

    // if their is only one elemennt in first linked list 
    if(first -> next == NULL){
        first -> next = second;
        return first;
    }

    Node<int>* curr1 = first;
    Node<int>* next1 = curr1 -> next;
    Node<int>* curr2 = second;
    Node<int>* next2 = curr2 -> next;

    while(curr2 != NULL && next1 != NULL){

        // insert data or element of second linked list between first linked list 
        if((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)){

            // add node in between the first list 
            curr1 -> next = curr2;
            next2 = curr2 -> next; 
            curr2 -> next = next1;

            // update pointers 
            curr1 = curr2;
            curr2 = next2;
        }
        // move curr1 and next1 forward
        else{

            curr1 = next1;
            next1 = next1 -> next;

            if(next1 == NULL){
                curr1 -> next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // if second list is empty 
    if(second == NULL){
        return first;
    }
    // if first list is empty 
    if(first == NULL){
        return second;
    }

    if(first -> data <= second -> data){
        return solve(first, second);
    }
    else{
        return solve(second,first);
    }
    return first;
}
