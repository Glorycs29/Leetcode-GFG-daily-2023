class Solution {
    private:
    void subSet(int idx, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans){
        // pick and no pick
        // if( arr[i]==arr[i-1])continue
        ans.push_back(ds);
        for(int i=idx; i<nums.size(); i++){
            if(i!=idx && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            subSet(i+1, nums, ds, ans);
            ds.pop_back();
        }
    }

  public:
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        // for unique elements, we'll accumulate same elements together
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        subSet(0, nums, ds, ans);
        return ans;
    }
};
