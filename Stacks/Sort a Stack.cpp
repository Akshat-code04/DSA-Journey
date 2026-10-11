#include <bits/stdc++.h> 
void sortedinsert(stack<int> &stack, int element){

	// base case 
	if(stack.empty() || (!stack.empty() && stack.top() < element) ){
		stack.push(element);
		return;
	}

	int n = stack.top();
	stack.pop();

	sortedinsert(stack, element);

	stack.push(n);
}

void sortStack(stack<int> &stack)
{
	// base case 
	if(stack.empty()){
		return;
	}

	int num = stack.top();
	stack.pop();

	sortStack(stack);

	sortedinsert(stack,num);
}
