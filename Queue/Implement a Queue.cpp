
#include <bits/stdc++.h> 
class Queue {

    int* arr;
    int qfront;
    int rear;
    int size;

public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty() {

        if(qfront == rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data) {
        // check if queue is full
        if(rear == size){
            cout<<"Queue is full ";
        }
        // if queue is not
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        // check if queue is empty 
        if(qfront == rear){
            return -1;
        }
        // if queue is not empty 
        else{
            int ans = arr[qfront];
            qfront++;
            if(qfront == rear){
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if(qfront == rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }
};
