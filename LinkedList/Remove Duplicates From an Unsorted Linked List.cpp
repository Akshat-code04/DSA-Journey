#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{
    // empty list
    if(head == NULL){
        return NULL;
    }

    unordered_map<int, bool> visited;

    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){

        // duplicate found
        if(visited[curr->data] == true){

            prev->next = curr->next;
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        else{
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}
