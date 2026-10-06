/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

// Approach 2
Node* getmiddle(Node* head){

    if(head == NULL || head -> next == NULL){
        return head;
    }

    // in case of 2 nodes only 
    if(head ->next->next == NULL){
        return head->next;
    }

    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }

        slow = slow->next;
    }
}

// Approach 1 
int getlen(Node* head){

    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

Node *findMiddle(Node *head) {
   return getmiddle(head);

   /* int len = getlen(head);
    int ans = (len/2);

    int cnt = 0;
    Node* temp = head;
    while(cnt < ans){
        temp = temp->next;
        cnt++;
    }
    return temp;*/
}

/*
    Approach 1 and 2
    Time Complexity = O(n)
*/


