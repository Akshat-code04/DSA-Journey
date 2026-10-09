class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Find the Transpose of the matrix
        for(int i = 0; i < n; i++) {
            // Start j from i + 1 to swap elements only above the main diagonal
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]); // Swap row and column elements
            }
        }

        // Step 2: Reverse each individual row of the transposed matrix
        for(int i = 0; i < n; i++) {
            // reverse() is a standard C++ function to flip a vector/row
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
