class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Initialize the last row of dp with the values from the last row of the matrix
        for (int j = 0; j < n; j++) {
            dp[n-1][j] = matrix[n-1][j];
        }

        // Fill the DP table from the second-last row upwards
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int leftDiagonal = (j > 0) ? dp[i+1][j-1] : INT_MAX;
                int down = dp[i+1][j];
                int rightDiagonal = (j < n-1) ? dp[i+1][j+1] : INT_MAX;
                
                dp[i][j] = matrix[i][j] + min(leftDiagonal, min(down, rightDiagonal));
            }
        }

        // The answer will be the minimum value in the first row of dp
        int minSum = INT_MAX;
        for (int j = 0; j < n; j++) {
            minSum = min(minSum, dp[0][j]);
        }

        return minSum;
    }
};
