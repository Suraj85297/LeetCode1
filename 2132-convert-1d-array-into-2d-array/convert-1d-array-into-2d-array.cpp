class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size()!=m*n){
            return{};
        }
        vector <vector <int>> result;
        int ind=0;
        while(m--){
            vector <int> ans;
            for(int i=ind; i<ind+n; i++){
                ans.push_back(original[i]);
            }
            result.push_back(ans);
            ind+=n;
        }
        return result;        
    }
};