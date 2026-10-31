class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        
        stack<int> s;
        
        // Store the elements of queue into the stack untill queue gets empty 
        while(!q.empty()){
            int element = q.front();
            q.pop();
            s.push(element);
        }
        
        // Restore the elemnts of stack into queue untill stack gets empty 
        while(!s.empty()){
            int element = s.top();
            s.pop();
            q.push(element);
        }
    }
    
};
