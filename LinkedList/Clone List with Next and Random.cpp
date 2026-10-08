/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};*/

// Approach - 1
class Solution {
    
  private:
    void insertattail(Node* &head, Node* &tail, int data){
        Node* newnode = new Node(data);
        
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail -> next = newnode;
            tail = newnode;
        }
    }
    
  public:
    Node* cloneLinkedList(Node* head) {
        
        // step 1 - Create a clone linked list 
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        
        Node* temp = head;
        
        while(temp != NULL){
            insertattail(clonehead, clonetail, temp -> data);
            temp = temp -> next;
        }
        
        // step 2 - Create a map 
        unordered_map<Node* , Node*> oldtonew;
        Node* originalnode = head;
        Node* clonenode = clonehead;
        
        while(originalnode != NULL && clonenode != NULL){
            oldtonew[originalnode] = clonenode;
            originalnode = originalnode -> next;
            clonenode = clonenode -> next;
        }
        
        originalnode = head;
        clonenode = clonehead;
        
        while(originalnode != NULL){
            clonenode -> random = oldtonew[originalnode -> random];
            originalnode = originalnode -> next;
            clonenode = clonenode -> next;
        }
        return clonehead;
        
    }
};
