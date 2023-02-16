int goodStones(int n,vector<int> &arr){
       vector<int> dp(n,0);
        // 0 non visited element
        // 1 bad stone
        // 2 good stone
        
        for(int i=0;i<n;i++){
            if(dp[i] == 0){
                int temp=i;
                bool good = false;
                while(dp[temp] != 1){
                    
                    //0 or no movement case
                    if(arr[temp] == 0) break;
                    
                    // mark visited
                    dp[temp] = 1;
                    
                    // next index
                    temp += arr[temp];
                    
                    //good stone or already a good stone
                    if(temp<0 || temp>=n || dp[temp] == 2){
                        good = true;
                        break;
                    }
                }
                
                //if good stone foound 
                // mark all index in the sequence as good elements
                if(good){
                    temp = i;
                    while(temp>=0 && temp<n){
                        dp[temp] = 2;
                        temp += arr[temp];
                    }
                }
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(dp[i] == 2){
                ans++;
            }
        }
        
        return ans;
    }  
