void insertatbottom(stack<int> &s, int element){

    // base case 
    if(s.empty()){
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();

    insertatbottom(s, element);

    s.push(num);
}

void reverseStack(stack<int> &stack) {
    
    // base case 
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();
    
    reverseStack(stack);

    insertatbottom(stack, num);
}
