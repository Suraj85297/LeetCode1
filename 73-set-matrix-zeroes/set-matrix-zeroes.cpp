#include <bits/stdc++.h>
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector <int> row(m,0);
        vector <int> col(n,0);
        MarkZeroes( matrix, row, col, m, n);
    }
    void MarkZeroes(vector <vector<int>> &matrix, vector<int> &row, vector<int> &col, int m, int n){

        for (int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for (int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(row[i]==1 || col[j]==1){
                    matrix[i][j]=0;
                }
            }        
        }
    }
};

/*class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);

        MarkZeroes(matrix, row, col, m, n);
    }

    void MarkZeroes(vector<vector<int>>& matrix, vector<int>& row, vector<int>& col, int m, int n) {
        // Mark the rows and columns that need to be zeroed
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Zero out the marked rows and columns
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};*/