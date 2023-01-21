class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    //let's use graph approach
	    
	    int n=nums.size();
	    vector<pair<int,int>> pos(n);
	    for(int i=0;i<n;i++){
	        pos[i].first=nums[i];
	        pos[i].second=i;
	    }
	    
	    sort(pos.begin(),pos.end());
	    //visited vector
	    vector<bool> vis(n,false);
	    int ans=0;
	    for(int i=0;i<n;i++){
	        
	        if(vis[i] || pos[i].second==i) continue; //pos[i]  : already sorted
	        
	        //until we get a cycle
	        int cycle_size=0;
	        int j=i;
	        
	        while(!vis[j]){
	            vis[j]=1;
	            j=pos[j].second;
	            cycle_size++;
	        }
	        
	        if(cycle_size>0){
	            ans+=(cycle_size-1);
	        }
	        
	    }
	    
	    return ans;
	    
	}
};
