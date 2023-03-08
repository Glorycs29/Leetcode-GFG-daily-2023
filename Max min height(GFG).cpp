class Solution
{
    public:
        #define ll long long
bool check(ll minHeight,int n,ll k,int w,vector <int> &a){
    queue<pair<int,ll>> q;
    ll prev=0;
    for(int i=0;i<n;i++){
        if(a[i]<minHeight){
            while(q.size()>0 and i-q.front().first>=w){
                prev-=q.front().second;
                q.pop();
            }
            ll req=minHeight-a[i]-prev;
            if(req<=0) continue;
            q.push({i,req});
            prev+=req;
            k-=req;
        }
    }
    return k>=0;
}
long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
{
    ll lo=0,hi=1e14,ans;
    while(lo<=hi){
        ll mid=(lo+hi)/2;
        if(check(mid,n,k,w,a)){
            ans=mid;
            lo=mid+1;
        }
        else
        hi=mid-1;
    }
    return ans;
}
};
