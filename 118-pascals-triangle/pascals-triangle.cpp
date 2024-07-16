class Solution {
public:
    vector <int> generatedRow(int n){
        vector <int> row;
        row.push_back(1);
        int ans = 1;
        for(int i = 1; i<n; i++ ){
            ans = ans*(n-i);
            ans = ans/i;
            row.push_back(ans);
        }
        return row;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for(int i=1; i<=numRows; i++){
            pascal.push_back(generatedRow(i));
        }
        return pascal;
    }
};