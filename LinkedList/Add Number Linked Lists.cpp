class Solution {
private:

    Node* reverse(Node* head) {

        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while (curr != NULL) {

            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }


    void insertAtTail(Node* &head, Node* &tail, int value) {

        Node* temp = new Node(value);

        if (head == NULL) {
            head = temp;
            tail = temp;
            return;
        }

        tail->next = temp;
        tail = temp;
    }


    Node* add(Node* first, Node* second) {

        int carry = 0;

        Node* ansHead = NULL;
        Node* ansTail = NULL;

        while (first != NULL || second != NULL || carry != 0) {

            int val1 = 0;

            if (first != NULL) {
                val1 = first->data;
            }

            int val2 = 0;

            if (second != NULL) {
                val2 = second->data;
            }

            int sum = carry + val1 + val2;

            int digit = sum % 10;

            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;

            if (first != NULL) {
                first = first->next;
            }

            if (second != NULL) {
                second = second->next;
            }
        }

        return ansHead;
    }


public:

    Node* addTwoLists(Node* head1, Node* head2) {

        // Step 1: Reverse both linked lists
        head1 = reverse(head1);
        head2 = reverse(head2);


        // Step 2: Add both reversed linked lists
        Node* ans = add(head1, head2);


        // Step 3: Reverse the answer
        ans = reverse(ans);


        // Step 4: Remove extra zeros at the beggining of the linked list
        while (ans != NULL && ans->data == 0 && ans->next != NULL) {

            Node* temp = ans;
            ans = ans->next;

            delete temp;
        }


        return ans;
    }
};
