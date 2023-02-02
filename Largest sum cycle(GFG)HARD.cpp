//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
//User function Template for C++
class Solution{
private:
    long long ans = -1;
    void dfs(int node,long long sum,vector<int> &adj,vector<int> &pref,vector<int> &vis){
        if(node == -1 or (vis[node] and pref[node] == -1)) return;
        if(vis[node] and pref[node] != -1){
            ans = max(ans,sum-pref[node]); return;
        }
        vis[node] = true; pref[node] = sum;
        dfs(adj[node],sum+node,adj,pref,vis);
        pref[node] = -1;
    }
public:
    long long largestSumCycle(int N, vector<int> edge){
        vector<int> pref(N,-1), vis(N);
        for(int node=0;node<N;node++){
            dfs(node,0,edge,pref,vis);
        }
        
       // cout<<"\n";
        
        
        return ans;
    }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends
