class Solution {
  
  private:
    vector<int> nextSmallerElement(vector<int>& arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        
        for(int i=n-1; i>=0; i--){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerElement(vector<int>& arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        
        for(int i=0; i<n; i++){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights,int n){
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
        
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int l = heights[i];

            // if the next element of not present than take the size of next equals to number of columns
          
            if(next[i] == -1){
                next[i] = n;
            }
            
            int b = next[i] - prev[i] -1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
  public:
    int maxArea(vector<vector<int>> &mat) {
    
        int n = mat.size();       // Number of rows
        int m = mat[0].size();    // Number of columns

        // for the first row of the matric 
        int area = largestRectangleArea(mat[0], m);
        
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] != 0){
                    // Updated row - add the element of next row if it is non-zero 
                    mat[i][j] = mat[i][j] + mat[i-1][j];
                }
                else{
                    mat[i][j] = 0;
                }
            }
            area = max(area,largestRectangleArea(mat[i], m));
        }
        return area;
        
    }
};
