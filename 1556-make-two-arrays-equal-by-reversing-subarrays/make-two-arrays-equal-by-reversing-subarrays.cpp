class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
         unordered_map <int,int> mp;
         for(auto &num:target){
            mp[num]++;
         }
         for(auto &num:arr){
            if(mp.find(num)==mp.end()){
                return false;
            }
            mp[num]--;
            if(mp[num]==0){
                mp.erase(num);
            }
         }
         return mp.size()==0;
    }
};