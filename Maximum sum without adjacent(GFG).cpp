class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    //sum1=odd //sum2=even
// 	    let's consider both options

// While we choose first option, 
//we cannot add its next element to our sum as sum cannot be of adjacent elements.
// If we choose second option, we can consider its next element to our sum
    vector<int> dp(n,0);

    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for(int i=2; i<n; i++){
        int include = arr[i]+dp[i-2];
        int exclude = dp[i-1];
        dp[i] = max(include, exclude);
    }
    return dp[n-1];
	    
	}
};
