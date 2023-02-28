class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        vector<int> ans(n,0);
        int i=0;
        while(i<n){
            ans[i]=ans[i-1] + (a[i]-a[i/2]);
            i++;
        }
        return ans;
    }
};
