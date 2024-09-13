/*class Solution {
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
};*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXor(n);
        prefixXor[0] = arr[0];
        
        // Compute prefix XOR for the array
        for (int i = 1; i < n; ++i) {
            prefixXor[i] = prefixXor[i - 1] ^ arr[i];
        }
        
        vector<int> ans;
        
        // Answer each query using the prefix XOR
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            if (left == 0) {
                ans.push_back(prefixXor[right]);
            } else {
                ans.push_back(prefixXor[right] ^ prefixXor[left - 1]);
            }
        }
        
        return ans;
    }
};
