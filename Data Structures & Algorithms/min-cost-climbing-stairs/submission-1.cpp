class Solution {
public:
    int memo(int i,int n,vector<int>& cost, vector<int>& dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];

        int one=memo(i+1,n,cost,dp);
        int two=memo(i+2,n,cost,dp);

        return dp[i]=cost[i]+min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        return min(memo(0,n,cost,dp1),memo(1,n,cost,dp2));
    }
};
