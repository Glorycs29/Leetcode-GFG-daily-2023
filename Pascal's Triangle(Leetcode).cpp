class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            vector<int> temp(i+1,1);
            if(i<=1){
                res.push_back(temp);
            }else{
                for(int j=1;j<=i-1;j++){
                    temp[j] = res[i-1][j-1] + res[i-1][j];   
                }
                
                res.push_back(temp);
            }
        }
        return res;
    }
};
