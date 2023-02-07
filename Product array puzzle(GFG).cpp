class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //either make two arrays
        // prefix product and suffix product
        
        vector<long long int> prefix(n,0);
        vector<long long int> sufix(n,0);
        vector<long long int> product(n,0);
        
        prefix[0]=1;
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        sufix[n-1]=1;
        for(int i=n-2;i>=0;i--){
            sufix[i]=sufix[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            product[i]=prefix[i]*sufix[i];
        }
        return product;
        
    }
};
