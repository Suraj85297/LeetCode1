class Solution {
public:
    vector <int> solve(string s){
        vector <int> result;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='+' || s[i]=='*' || s[i]=='-'){
                vector <int> left_exp = solve(s.substr(0,i));
                vector <int> right_exp = solve(s.substr(i+1));
                 for(int x : left_exp){
                    for(int y : right_exp){
                        if(s[i]=='+'){
                            result.push_back(x+y);
                        }
                        if(s[i]=='-'){
                            result.push_back(x-y);
                        }
                        if(s[i]=='*'){
                            result.push_back(x*y);
                        }
                    }
                 }
            }
        }
        if(result.empty()){
            result.push_back(stoi(s));
        }
        return result;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};