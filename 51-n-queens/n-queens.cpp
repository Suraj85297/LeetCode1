class Solution {
public:
    void solve(vector <vector <string>> &ans, vector <string> &board, int n, vector <int> &leftRow, vector<int> &upperDiagonal, vector <int> &lowerDiagonal, int col){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(leftRow[row]==0 && upperDiagonal[col-row+n-1]==0 && lowerDiagonal[row+col]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                upperDiagonal[col-row+n-1]=1;
                lowerDiagonal[row+col]=1;
                solve(ans,board,n,leftRow,upperDiagonal,lowerDiagonal,col+1);
                board[row][col]='.';
                leftRow[row]=0;
                upperDiagonal[col-row+n-1]=0;
                lowerDiagonal[row+col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector <vector <string>> ans;
        vector<string> board(n, string(n, '.'));
        vector <int> leftRow (n,0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
        solve(ans,board,n,leftRow,upperDiagonal,lowerDiagonal,0);
        return ans;
    }
};