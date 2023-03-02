class Solution{
public:
    int minCost(vector<vector<int>> &cost) {
        int n = cost.size(), k = cost[0].size();
        if(k == 1){
            if(n == 1)
                return cost[0][0];
            return -1;
        }
        pair<int,int> mini = {INT_MAX,-1}, smini = {INT_MAX,-1};
        for(int i=0; i<k; i++){
            if(cost[0][i] < mini.first){
                smini = mini;
                mini = {cost[0][i], i};
            }
            else if(cost[0][i] < smini.first)
                smini = {cost[0][i], i};
        }
        
        for(int i=1; i<n; i++){
            pair<int,int> curMini = {INT_MAX,-1}, curSmini = {INT_MAX,-1};
            
            for(int j=0; j<k; j++){
                int x = cost[i][j];
                if(j != mini.second)
                    x += mini.first;
                else
                    x += smini.first;
                if(x < curMini.first){
                    curSmini = curMini;
                    curMini = {x, j};
                }
                else if(x < curSmini.first)
                    curSmini = {x, j};
            }
            mini = curMini;
            smini = curSmini;
        }
        return mini.first;
    }
};
