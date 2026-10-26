
#include <bits/stdc++.h> 
class CircularQueue{

    int *arr;
    int front;
    int rear;
    int size;

    public:
    
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool enqueue(int value){
        // check if the queue is full 
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1) ) ){
            // queue is full 
            return false;
        }
        // insert first element 
        else if(front == -1){
            rear = front = 0;
        }
        // to maintain the cyclic order 
        else if(rear == size-1 && front != 0){
            rear = 0;
        }
        // normal flow
        else{
            rear++;
        }

        arr[rear] = value;

        return true;
       
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // check if the queue is empty 
        if(front == -1){
            // queue is empty 
            return -1;
        }
        // only single element is present
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){
            front = rear = -1;
        }
        // to maintain cyclic order 
        else if(front == size-1){
            front = 0;
        }
        
        // normal flow 
        else{
            front++;
        }
        return ans;
    }
};
