class Solution {
public:
    int solve(int i, int m, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp){
        if(i==m-1){
            return triangle[i][j];
        }
        if(i>m) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int down1=solve(i+1,m,j+1,triangle,dp);
        int down2=solve(i+1,m,j,triangle,dp);
        return dp[i][j]=triangle[i][j]+min(down1,down2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return solve(0,m,0,triangle,dp);
    }
};