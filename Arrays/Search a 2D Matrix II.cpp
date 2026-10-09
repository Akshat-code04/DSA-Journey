class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // top right search 
        int row = matrix.size();
        int col = matrix[0].size();

        int rowindex = 0;
        int colindex = col -1; // last column 

        while(rowindex < row && colindex >= 0){
            int element = matrix[rowindex][colindex];

            if(element == target){
                return true;
            }
            else if(element < target){
                rowindex++;
            }
            else{
                colindex--;
            }
        }
        return false;
    }
};
