class Solution {
  public:
    int getMinimumDays(int N,string S, vector<int> &P) {
        // code here
        int l=0,r=N,ans=N;
    while(l<=r)
    {
          int m=(l+r)/2;
          string s=S;
          for(int i=0;i<m;i++) s[P[i]]='?';
          bool is=1;
          for(int i=1;i<N;i++) if(s[i]!='?' && s[i]==s[i-1]) is=0;
          if(is) r=m-1, ans=min(ans,m); 
          else l=m+1;
    }
    return ans;
    }
};
