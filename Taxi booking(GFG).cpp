class Solution{
public:
    int minimumTime(int n,int cur,vector<int> &pos,vector<int> &time){
        int mini_time=INT_MAX;
        for(int i=0;i<n;i++){
            int cur_time= abs(cur-pos[i])*time[i];
            mini_time=min(mini_time, cur_time);
        }
        return mini_time;
        
    }
};
