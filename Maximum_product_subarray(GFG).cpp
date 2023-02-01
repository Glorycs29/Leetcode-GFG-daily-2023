//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

    long long maxProduct(vector<int> arr, int n) {
    	    // code here
    	    long long ans= INT_MIN;
    	    long long prod = 1;
    	    
    	    for(int i = 0; i<arr.size(); i++){
    	        prod*=arr[i];
    	        ans = max(ans,prod);
    	        if(prod==0) prod=1;
    	    }
    	    
    	    prod = 1;
    	    for(int i = arr.size()-1; i>=0; i--){
    	        prod*=arr[i];
    	        ans = max(ans,prod);
    	        if(prod==0) prod=1;
    	    }
    	    
    	    return ans;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
