class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
     // create a visisted arr for row
     // it will store either the  ith row is visited or not
     // in same was for column
     
     vector<int> row(n,0);
     vector<int> col(n,0);
     vector<long long int> ans;
     
     int r_count=0;
     int c_count=0;
     
     for(int i=0;i<k;i++){
         int r = arr[i][0]-1;
         int c = arr[i][1]-1;
         
         if(row[r]==0){
             row[r]=1;
             r_count++;
         }
         
         if(col[c]==0){
             col[c]=1;
             c_count++;
         }
         
         ans.push_back(n*n-(r_count*n)-(c_count*n)+(r_count*c_count)); // r_count*c_count are those overlapping ..jo do baar minus ho jaaenge
         
     }
     
     return ans;
  }
};
