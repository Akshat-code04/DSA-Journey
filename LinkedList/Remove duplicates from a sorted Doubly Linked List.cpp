/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 **************************************************************************/

Node * removeDuplicates(Node *head)
{
    // empty list 
    if(head == NULL){
        return NULL;
    }
    Node* curr = head;

    while(curr != NULL && curr -> next != NULL){

        if(curr -> data == curr -> next -> data){
            Node* next_to_next = curr -> next -> next;
            Node* node_to_delete = curr -> next;
            delete(node_to_delete);
            curr -> next = next_to_next;
        }
        else{
            curr = curr -> next;
        }
    }
    return head;
}

