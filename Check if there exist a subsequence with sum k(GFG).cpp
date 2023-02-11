class Solution{
    public:
    
    bool fun(int i, vector<int>& arr, int n, int k, int sum){
        
        if(sum>k) return false;
        if(sum==k) return true;
        if(i==n)
            if(sum!=k) return false;
            
        if(fun(i+1, arr, n, k, sum+arr[i])) return true;
        if(fun(i+1, arr, n, k, sum)) return true;
        
        return false;
    }
    
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        int sum=0;
        return fun(0,arr,n,k,sum);
    }
};
