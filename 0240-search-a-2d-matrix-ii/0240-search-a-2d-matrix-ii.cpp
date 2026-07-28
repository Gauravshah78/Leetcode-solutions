class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n = matrix.size();       // Number of rows
        int m = matrix[0].size();    // Number of columns

        int row = 0;        // Start from first row
        int col = m - 1;    // Start from last column (top-right corner)

        // Traverse the matrix
        while (row < n && col >= 0) {
            if (matrix[row][col] == target) {
                return true; // Found target
            } 
            else if (matrix[row][col] < target) {
                row++; // Move down to next row
            } 
            else {
                col--; // Move left to previous column
            }
        }

        return false; 
    }
};