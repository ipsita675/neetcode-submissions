class Solution {
public:
    int memo(int r,int c,int m,int n,vector<vector<int>>& dp,vector<vector<int>>& grid){
        if(r==m-1 && c==n-1)return grid[m-1][n-1];
        if(r>=m || c>=n)return 1e9;
        if(dp[r][c]!=1e9)return dp[r][c];

        int down=memo(r+1,c,m,n,dp,grid);
        int right=memo(r,c+1,m,n,dp,grid);

        return dp[r][c]=grid[r][c]+min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,1e9));
        return memo(0,0,m,n,dp,grid);
    }
};