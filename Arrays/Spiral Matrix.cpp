class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int total = row*col;

        int startrow = 0;
        int endrow = row - 1;
        int startcol = 0;
        int endcol = col - 1;
        int count = 0;

        while(count < total){

            // print the starting row 
            for(int index = startcol; index<=endcol && count < total; index++){
                ans.push_back(matrix[startrow][index]);
                count++;
            }
            startrow++;

            // print ending column
            for(int index = startrow; index <= endrow && count < total; index++){
                ans.push_back(matrix[index][endcol]);
                count++;
            }
            endcol--;

            // print ending row 
            for(int index = endcol; index >= startcol && count < total; index--){
                ans.push_back(matrix[endrow][index]);
                count++;
            }
            endrow--;

            //print starting column 
            for(int index = endrow; index >= startrow && count < total; index--){
                ans.push_back(matrix[index][startcol]);
                count++;
            }
            startcol++;
        }
        return ans;
    }
};

// Time complexity --> O(m*n)
