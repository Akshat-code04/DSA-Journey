class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        
        stack<int> s;
        
        // in case if window size is greater than size of queue or less than 0 
        if(k <= 0 || k > q.size()) {
            return q;
        }
        
        // step 1 - store the elements from queue into stack 
        for(int i=0;i<k;i++){
            int val = q.front();
            q.pop();
            s.push(val);
        }
        
        // step 2 - again store those element into queue 
        while(!s.empty()){
            int val = s.top();
            s.pop();
            q.push(val);
        }
        
        int t = q.size() - k;
        
        for(int i=0; i<t; i++){
            int val = q.front();
            q.pop();
            q.push(val);
        }
        
        return q;
    }
};
