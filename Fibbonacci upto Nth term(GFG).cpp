class Solution{ 
public:
    vector<long long> Series(int n) {
        
        if(n==0)return {0};
        if(n==1)return {0,1};
        
        
        vector<long long> fib(n+1,0);
        fib[0]=0;
        fib[1]=1;
        solve(2,n,fib);
        return fib;
        
    }
    
    void solve(int idx, int n, vector<long long>& fib){
        if(idx==n){
            fib[idx]=fib[idx-1]+fib[idx-2];
            return;
        }
        fib[idx]=fib[idx-1]+fib[idx-2];
        solve(idx+1,n,fib);
    }
};
