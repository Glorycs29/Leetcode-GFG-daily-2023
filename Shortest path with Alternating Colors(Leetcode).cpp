class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        // adjlist
        //rededge-->0
        //blueedge-->1
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:redEdges){
            adj[it[0]].push_back({it[1],0});
        }
        for(auto &it:blueEdges){
            adj[it[0]].push_back({it[1],1});
        }
        //shortest distance
        vector<int>ans(n,-1);
        queue<vector<int>> q; // node // steps //color
        vector<vector<bool>> visited(n, vector<bool>(2)); // node // color

        q.push({0,0,-1});
        visited[0][0]= true;
        visited[0][1]= true;
        ans[0]=0;
        while(!q.empty()){
            vector<int> cur = q.front(); q.pop();
            int node = cur[0], steps = cur[1], prevColor = cur[2];
            // neighbour
            for(auto &[nbr,color] : adj[node]){
                if(!visited[nbr][color] && color!=prevColor){
                    visited[nbr][color]=true;
                    q.push({nbr, steps+1, color});

                    if(ans[nbr]==-1){
                        ans[nbr]=steps+1;
                    }
                }
            }
        }
        return ans;
    }
};
