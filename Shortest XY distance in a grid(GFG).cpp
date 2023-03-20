class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // a visisted array to store thst whether the cell is visited or not
        // a queue to store the col_no , row_no and distance associated
        vector<vector<int>> vis(N, vector<int> (M, 0));
        queue<pair<pair<int,int>,int>> q;    // row, col and distance.
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j] == 'X'){
                    // mark visited all cells containing 'X'
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        
        // initially take minimum ans generically as INT_MAX
        int ans = INT_MAX;
        // now use direction ratios to reach other neighbours
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                // neighbours row and column
                int nrow = delrow[i]+row;
                int ncol = delcol[i]+col;
                // now check for vaild condition of neighbour
                if(nrow>=0 && nrow<N && ncol>=0 && ncol<M && !vis[nrow][ncol]){
                    if(grid[nrow][ncol] == 'Y'){
                        // if neighbour is found to be 'Y' then update the ans as minimum one
                        ans = min(ans,dist+1);
                    }
                    else{
                        // if it is not equals to Y then increase the distance by 1 for this column
                        q.push({{nrow,ncol},dist+1});
                    }
                    // mark vivited to visited neighbour 
                    vis[nrow][ncol]=1;
                }
            }
        }
        return ans;
    }
};
