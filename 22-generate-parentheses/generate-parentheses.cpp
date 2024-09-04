class Solution {
public:
    void solve(vector <string> &ans, string brackets, int open, int close, int n){
        if(open==close && open+close==n*2){
            ans.push_back(brackets);
            return;
        }
        if(open<n){
            solve(ans, brackets + "(", open+1, close, n);
        }
        if(close<open){
            solve(ans, brackets + ")" , open, close+1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector <string> ans;
        string brackets;
        solve(ans, brackets, 0, 0, n);
        return ans;
    }
};