class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        long long d_pairs=0;
        // sort half of the array
        sort(arr.begin(), arr.begin()+n/2);
        
        for(int j=n/2;j<n;j++){
            
            int x = arr[j]*5;
            auto end = arr.begin() + (n/2); 
        // using stl
            int i = lower_bound(arr.begin(), end, x) - arr.begin() ;
            d_pairs += (n/2-i); 
            
        }
        
        return d_pairs;
    }  
};
