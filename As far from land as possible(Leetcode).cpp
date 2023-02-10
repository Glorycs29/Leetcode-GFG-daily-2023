class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // size of row and col
        int row=grid.size(), col = grid[0].size();
        // bfs from every one'1' to find maximum distance
        queue<pair<int,int>>q;
        // push all one's in queue
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1) q.push({i,j});
            }
        }
        int res=0;
        // apply bfs
        while(!q.empty()){

            int temp_i=q.front().first;
            int temp_j=q.front().second;
            q.pop();

            vector<pair<int,int>> dir= {{1,0}, {0,1}, {-1,0}, {0,-1}};
            // traverse over neighbours
            for(auto &it:dir){
                int new_i=it.first+temp_i;
                int new_j=it.second+temp_j;
            

            //checking valid condition
                if(new_i>=0 && new_i<row && new_j>=0 && new_j<col && grid[new_i][new_j]==0){
                    q.push({new_i, new_j});
                    grid[new_i][new_j]=grid[temp_i][temp_j]+1;
                    res = max(res,grid[new_i][new_j]);
                }
            }
        }

        return res-1;
    }
};
