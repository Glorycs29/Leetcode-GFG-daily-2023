
/*
long long int fun(int r[],int g[],int b[],int prev,int ind,vector<vector<long long int>> &dp,int n){
        if(ind>=n){
            return 0;
        }
        if(dp[ind][prev]!=-1){
            return dp[ind][prev];
        }
        // 3 cases
        long long int c1=1e12;
        if(prev!=0){
            c1 = r[ind] + fun(r,g,b,0,ind+1,dp,n);
        }
        long long int c2=1e12;
        if(prev!=1){
            c2 = g[ind] + fun(r,g,b,1,ind+1,dp,n);
        }
        long long int c3=1e12;
        if(prev!=2){
            c3 = b[ind] + fun(r,g,b,2,ind+1,dp,n);
        }
        return dp[ind][prev] = min(c1,min(c2,c3));
    } 
    long long int distinctColoring(int n, int r[], int g[], int b[]){
        
        // code here 
        // 3 - no color 
        // 2 - blue
        // 1 - green
        // 0 - red
        vector<vector<long long int>> dp(n,vector<long long int> (4,-1));
        fun(r,g,b,3,0,dp,n);
        return dp[0][3];
    }



*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int n, int r[], int g[], int b[]){
        //create a dp table of (n*3) size
        vector<vector<long long int>> dp(n,vector<long long int>(3,0));
        dp[0][0]=r[0];
        dp[0][1]=g[0];
        dp[0][2]=b[0];
        
        for(int i=1;i<n;i++){
            //for red color
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + r[i];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + g[i];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + b[i];
        }
        return min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends
