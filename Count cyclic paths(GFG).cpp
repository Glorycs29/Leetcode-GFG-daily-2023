class Solution{   
public:
    int countPaths(int n){
         if(n==1)return 0;
         
         long long ans=0;
         for(int i=2;i<=n;i++){
             if(i%2==0)
                 ans=3*(ans+1);
             else
                 ans=3*(ans-1);
             ans=ans%1000000007;
         }
         return ans;
    }
};
