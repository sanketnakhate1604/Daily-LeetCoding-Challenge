class Solution {
public:
     vector<int> memo = vector<int>(46, -1);
    int climbStairs(int n) {
        if(n<=0){
            return 1;
        }

        if(memo[n]!=-1){
            return memo[n];
        }

        int step1=climbStairs(n-1);
        int step2=0;
        if(n>=2)
           step2=climbStairs(n-2);

        return memo[n]=step1+step2;
    }
};