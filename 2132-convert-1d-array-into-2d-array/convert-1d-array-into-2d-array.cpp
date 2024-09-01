/*class Solution {
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
};*/
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Check if the total number of elements matches
        if (original.size() != m * n) {
            return {};
        }

        vector<vector<int>> result(m, vector<int>(n));

        // Fill the 2D array by mapping elements from the original array
        for (int i = 0; i < original.size(); i++) {
            result[i / n][i % n] = original[i];
        }

        return result;
    }
};
