class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        //create a vector pair(ages,score) //so that after sorting there'll be no use of ages
        int n=scores.size();
        vector<pair<int,int>> arr;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            arr.push_back({ages[i], scores[i]});
        } 
        sort(arr.begin(), arr.end());
        int res=0;
        for(int i=0;i<n;i++){
            ans[i]=arr[i].second;
            for(int j=0;j<i;j++){
                if(arr[i].second >= arr[j].second){
                    //bikull favourable hai
                    ans[i]= max(ans[i], ans[j]+arr[i].second);
                }
            }
            res = max(res,ans[i]);
        }
        return res;
    }
};
