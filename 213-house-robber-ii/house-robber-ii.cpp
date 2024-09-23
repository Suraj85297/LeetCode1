class Solution {
public:
    int maxNonAdjacentSum(vector<int> num){
        int prev=num[0];
        int prev2=0;
        for(int i=1; i<num.size(); i++){
            int take=num[i];
            if(i>1) take+=prev2;
            int nonTake=0+prev;
            int curri=max(take,nonTake);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int>temp1, temp2;
        if(nums.size()==1) return nums[0];
        for(int i=0; i<nums.size(); i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(maxNonAdjacentSum(temp1),maxNonAdjacentSum(temp2));
    }
};