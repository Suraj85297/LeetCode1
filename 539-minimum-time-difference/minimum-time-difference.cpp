class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector <int> minutes;
        for(string timePoint : timePoints){
            int h = stoi(timePoint.substr(0,2));
            int m = stoi(timePoint.substr(3,2));
            minutes.push_back(h*60 + m);
        }
        sort(minutes.begin(),minutes.end());
        int minDiff=INT_MAX;
        for(int i=1; i<minutes.size(); i++){
            minDiff=min(minDiff,minutes[i]-minutes[i-1]);
        }
        int circDiff = 1440 + minutes[0] - minutes.back();
        return min(minDiff,circDiff);
   }
};