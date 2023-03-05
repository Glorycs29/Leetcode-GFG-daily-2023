class Solution {
  public:
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        vector<int> adj[N+1];
        for(int i=1; i<N; i++)
            adj[P[i]].push_back(i+1);
        
        vector<vector<long long>> dp(N+1, vector<long long>(2, -1e18));
        
        for(int i=1; i<=N; i++){
            dfs(i, adj, A, dp, 0);
        }
        
        long long ans = -1e18;
        for(int i=1; i<=N; i++)
            ans = max(ans, dp[i][0]);
        return ans;
    }
    void dfs(int node, vector<int> adj[], vector<int> &A, vector<vector<long long>> &dp, bool f){
        if(dp[node][f] != -1e18)
            return;
        long long ans = -1e18;
        for(int child: adj[node]){
            dfs(child, adj, A, dp, !f);
            ans = max(ans, dp[child][!f]);
        }
        long long nodeVal = A[node-1];
        if(f)
            nodeVal = -nodeVal;
        if(ans == -1e18)
            dp[node][f] = nodeVal;
        else
            dp[node][f] = nodeVal + ans;
    }
};
