#include<stack>
class SpecialStack {
    public:
    stack<int> s;
    int mini;

    void push(int data) {
        // if stack is empty
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if(data < mini){
                int value = 2*data - mini;
                s.push(value);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
        
    }

    int pop() {
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        s.pop();
        if(curr > mini){
            return curr;
        }
        else{
            int prevmini = mini;
            int value = 2*mini - curr;
            mini = value;
            return prevmini;
        }
    }

    int top() {
        // if stack is empty 
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        if(mini > curr){
            return mini;
        }
        else{
            return curr;
        }
    }
    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty()){
            return -1;
        }

        return mini;
    }  
};
