class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        dp.resize(nums.size()+1,-1); 
       return rob(nums,nums.size()-1);
    }

private:
    int rob(vector<int>& nums, int i){
        if(i<0)return 0;
        if(dp[i] != -1){
            return dp[i];
        }
        int result = max(rob(nums, i-1), nums[i]+rob(nums,i-2));
        dp[i]=result;
        return result;
    }
};
