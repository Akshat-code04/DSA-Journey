class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        
        deque<int> dq;
        vector<int> ans;
        
        // process the first window of k size 
        for(int i=0; i<k; i++){
            // if you get the negative element push the index of that element into dq
            if(arr[i] < 0){
                dq.push_back(i);
            }
        }
        
        // store the answer of first window 
        if(dq.size() > 0){
            // store the index as a answer 
            ans.push_back(arr[dq.front()]);
        }
        else{
            // if you didn't any negative element then store 0 in your answer 
            ans.push_back(0);
        }
        
        // process for remaining windows 
        for(int i=k; i<arr.size(); i++){
            //removal 
            if(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }
            
            // adding further negative element's index
            if(arr[i] < 0){
                dq.push_back(i);
            }
            
            // store the answer 
            if(dq.size() > 0){
                ans.push_back(arr[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};
