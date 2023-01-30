class Solution{
    vector<int> visited;
    int ans=0;
    bool solve(int node, vector<vector<int>> &adj){
        bool select = false;        //need to select curr node or not
        visited[node] = true;
        for(auto nbr : adj[node])
        {
            if(!visited[nbr]){      
                bool isChildSelected = solve(nbr, adj);     //check kya kisi child par light algaya he 
                
                if(isChildSelected == false)//agar child par light nhi lagaya he to curr node par lagana hi padega 
                    select = true;      
            }
        }
        if(select)  
            ans++;
            
        return select;
    }
  public:
    int countVertex(int n, vector<vector<int>>edges){
        vector<vector<int>> adj(n+1);
        for(auto p : edges){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        visited.resize(n+1,0);
        solve(1, adj);
        if(ans == 0)
            ans++;
        return ans;
    }
};





// int count=0;
//      bool dfs(vector<vector<int>>&adj,int par,vector<int>&vis){
//          vis[par]=1;
//          bool flag=false;
//          for(auto x:adj[par]){
//              if(!vis[x] and !dfs(adj,x,vis))flag=true;
//          }
//          count+=flag;
//          return flag;
//      }
//     int countVertex(int N, vector<vector<int>>edges){
//         // code here
      
//         vector<vector<int>>adj(N+1);
//         vector<int>vis(N+1,0);
//         for(auto e : edges){
//             adj[e[0]].push_back(e[1]);
//             adj[e[1]].push_back(e[0]);
//         }
//          dfs(adj,1,vis);
//         return count;
//     }
