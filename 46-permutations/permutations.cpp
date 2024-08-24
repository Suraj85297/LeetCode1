class Solution {
public:
    void fn(int index, vector <int> &nums, vector <vector <int>> &ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[index],nums[i]);
            fn(index+1,nums,ans);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector <int>> ans;
        fn(0,nums,ans);
        return ans;
    }
};
/*
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
*/