class Solution {
public:
    
    int tribonacci(int n) {
        
        
        if(n<=1) return n;
        else if(n==2) return 1;
        
        long long int dp;
        long long int pota = 0;
        long long int baap = 1;
        long long int dada = 1;
        for(int i=3;i<=n;i++){
            dp = pota+baap+dada;
            pota = baap;
            baap = dada;
            dada = dp;
        }
        return dp;
    }
};



// tc= O(n) SC = O(1)

// by using static array

int tribonacci(int n) {
  int dp[3] = {0, 1, 1};
  for (int i = 3; i <= n; ++i)
    dp[i%3] += dp[(i+1)%3] + dp[(i+2)%3];
  return dp[n%3];
}
