/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};*/

class Solution {
  private:
    Node* getmid(Node* head){
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    Node* reverse(Node* head){
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
  public:
    bool isPalindrome(Node *head) {
        
        if(head -> next == NULL){
            return true;
        }
        
        // step 1 - find the middle element of the linked list 
        Node* middle = getmid(head);
        
        // step 2 - reverse the linked list after the middle element 
        Node* temp = middle -> next;
        middle -> next = reverse(temp);
        
        // step 3 - Comppare the linked list after the middle element with linked list before the middle element 
        Node* head1 = head;
        Node* head2 = middle -> next;
        
        while(head2 != NULL){

            if(head1->data != head2->data){

                // Restore list before returning
                temp = middle->next;
                middle->next = reverse(temp);

                return false;
            }

            head1 = head1->next;
            head2 = head2->next;
        }
        // step 4 - repeat the step 2 
        
        temp = middle -> next;
        middle -> next = reverse(temp);
        
        return true;
    }
};  
