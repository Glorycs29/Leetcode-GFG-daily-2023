class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int n) {
    //     as it is mentioned that the arrays are sorted so we can use binary search
    //     int mxcount = 0;
    //     int row_num = 0;
    //     for(int i = 0; i<N; i++){
    //          vector<int>::iterator upper;
    //          upper = upper_bound(mat[i].begin(), mat[i].end(), 0) ;
    //          int temp =  N - (upper - mat[i].begin());
    //          if(temp > mxcount){
    //              mxcount = temp;
    //              row_num = i;
    //          }
    //     }
    //   return {row_num , mxcount};
 
        int row_number=0, max_cnt=0;
        for(int i=0;i<n;i++){
            int cur_cnt=0;
            for(int j=0;j<n;j++){
                cur_cnt+=mat[i][j];
            }
            if(max_cnt<cur_cnt){
                max_cnt=cur_cnt;
                row_number=i;
            }
        }
         return {row_number, max_cnt};
    }
};
