

// binary search

typedef long long ll;
class Solution {
public:
    bool check(vector<int>& time,ll mid,ll t){
        ll trips=0;
        for(auto &i:time){
            trips+=(mid/i);
            if(trips>=t) return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int t) {
        int n=time.size();
        sort(time.begin(),time.end());
        ll r=(ll)time[0];
        ll h=(ll)time[n-1]*(ll)t;
        while(r<h){
            ll mid=r+(h-r)/2;
            if(check(time,mid,t)){
                h=mid;
            }else r=mid+1;
        }
        return r;

    }
};
