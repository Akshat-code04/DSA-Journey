class Solution {
  public:
    string firstNonRepeating(string &s) {
        
        unordered_map<char , int> count;
        queue<int> q;
        string ans =  "";
        
        for(int i=0; i<s.length(); i++){
            // store the current character of the string 
            char ch = s[i];
            
            // increase the count of the current character 
            count[ch]++;
            
            // push the current character into the queue 
            q.push(ch);
            
            
            while(!q.empty()){
                // check if any character is repeating 
                if(count[q.front()] > 1){
                    // remove that character 
                    q.pop();
                }
                else{
                    // push the element that occurs only ones 
                    ans.push_back(q.front());
                    break;
                }
            }
            // if your queue is empty then their is no non-repeating character 
            if(q.empty()){
                ans.push_back('#');
            }
            
        }
        return ans;
        
    }
};
