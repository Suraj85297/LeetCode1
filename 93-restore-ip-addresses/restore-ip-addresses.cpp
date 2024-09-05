class Solution {
public:
    bool isValid(string str){
        if(str[0]=='0' && str.size()>1){
            return false;
        }
        int val = stoi(str);
        return val<=255;
    }
    void solve(string s, vector <string> &ans, string IP, int index, int parts, int n){
        if(index==n && parts==4){
            IP.pop_back(); //removing last dot
            ans.push_back(IP);
            return;
        }
        if(index+1<=n){
            solve(s, ans, IP + s.substr(index,1) + '.', index+1, parts +1, n);
        }
        if(index+2<=n && isValid(s.substr(index,2))){
            solve(s, ans, IP + s.substr(index,2) + '.', index+2, parts +1, n);
        }
        if(index+3<=n && isValid(s.substr(index,3))){
            solve(s, ans, IP + s.substr(index,3) + '.', index+3, parts +1, n);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size()>12){
            return {};
        }
        vector <string> ans;
        string IP;
        solve(s,ans,IP,0,0,s.size());
        return ans;
    }
};