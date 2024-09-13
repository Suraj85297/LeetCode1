class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector <int> ans;
        int j=0;
        while(j<queries.size()){
        int left = queries[j][0];
        int right = queries[j][1];
        int xorElement=arr[left];
        for(int i=left+1; i<=right; i++){
            xorElement^=arr[i];
        }
            ans.push_back(xorElement);
            j++;
        }
        return ans;
    }
};