class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int x = *max_element(candies.begin(), candies.end());
        vector<bool> ans(n,false); 

        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies >= x){
                ans[i]=true;
            }
        }
        return ans;
    }
};
