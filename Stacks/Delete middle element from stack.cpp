#include <bits/stdc++.h> 

void solve(stack<int>&inputStack, int count, int size){

   // base case - remove the middle element 
   if(count == size/2){
      inputStack.pop();
      return;
   }
   // storing the top element of stack untill we get the middle one 
   int num = inputStack.top();
   inputStack.pop();

   // recursive call 
   solve(inputStack,count+1,size);

   // push the element that we stored earlier 
   inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   int count = 0;
   solve(inputStack, count, N);
}
