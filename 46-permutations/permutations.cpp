class Solution {
public:
    void fn(vector <vector <int>> &ans, vector <int> &ds, vector <int> &nums, vector <int> &freq){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(freq[i]==0){
                ds.push_back(nums[i]);
                freq[i]=1;
                fn(ans,ds,nums,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector <int>> ans;
        vector <int> ds;
        vector <int> freq(nums.size(),0);
        fn(ans, ds, nums, freq);
        return ans;
    }
};