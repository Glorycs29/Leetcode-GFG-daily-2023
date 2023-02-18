class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        int ans=nums[n-1]-nums[0];
        
        ans=min(ans,max(0,nums[n-1]-nums[2]));
        ans=min(ans,max(0,nums[n-3]-nums[0]));
        ans=min(ans,max(0,nums[n-2]-nums[1]));
        
        return ans;
    }
};
