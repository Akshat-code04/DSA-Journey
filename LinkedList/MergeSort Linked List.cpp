/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/

node* findmid(node* head){

    node* slow = head;
    node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}
// merge 2 sorted linked list 
node* merge(node* left, node* right){

    // if first half is empty
    if(left == NULL){
        return right;
    }
    // if second half is empty
    if(right == NULL){
        return left;
    }

    node* ans = new node(-1);
    node* temp = ans;

    while(left != NULL && right != NULL){
        if(left -> data < right -> data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    while(left != NULL){
        temp -> next = left;
        temp = left;
        left = left -> next;
    }

    while(right != NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    ans = ans -> next;
    return ans;
    
}

node* mergeSort(node *head) {
    

    // base case 
    if(head == NULL || head -> next == NULL){
        return head;
    }

    // break the list into two halves , after getting the middle node 
    node* mid = findmid(head);

    node* left = head;
    node* right = mid -> next;
    mid -> next = NULL;

    // recursive case 
    left = mergeSort(left);
    right = mergeSort(right);

    node* result = merge(left, right);

    return result;
}
