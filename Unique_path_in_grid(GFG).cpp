class Solution {
  public:
  #define mod (int)(1e9+7)
  int fun(int x, int y, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
    
        // if invalid or grid ki value zero ho to vahan ja nhi skte  
        if(x>=n || y>=m || grid[x][y]==0)return 0;
        
        // destination // increase the count
        if(x==n-1 && y==m-1)return 1;
        
        
        if(dp[x][y]!=-1) return dp[x][y];
      
        int down=fun(x+1, y, n ,m, grid, dp);
        int right=fun(x, y+1, n ,m, grid, dp);
        
        return dp[x][y]=(down+right)%mod;
      
  }
  
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return fun(0, 0, n, m, grid, dp);
        }
};
