class Solution {
public:
    void solve(string mapping[], string &output, vector <string> &ans, string &digits, int index){
        if(index>=digits.size()){
            ans.push_back(output);
            return;
        }
        int num = digits[index]-48;
        string value = mapping[num];
        for(int j=0; j<value.size(); j++){
            output.push_back(value[j]);
            solve(mapping, output, ans, digits, index+1);
            output.pop_back();
        }
    }    vector<string> letterCombinations(string digits) {
        string mapping [10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector <string> ans;
        string output;
        if(digits.size()==0){
            return ans;
        }
        solve(mapping, output, ans, digits, 0);
        return ans;
    }
};