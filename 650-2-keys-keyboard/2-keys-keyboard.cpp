class Solution {
public:
    int getAllPrimeFactors(int num){
        int ans=0;
        while(num%2==0){
            ans += 2;
            num /= 2;
        }
        for(int i=3; i<=num; i+=2){
            while(num%i==0){
                ans += i;
                num /= i;
            }
        }
        return ans;
    }
    int minSteps(int n) {
        return getAllPrimeFactors(n);
    }
};