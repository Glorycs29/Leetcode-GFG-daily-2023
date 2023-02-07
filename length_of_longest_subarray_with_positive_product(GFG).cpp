int maxLength(vector<int> &arr,int n){
           // making four variable
    
        int first_neg =-1, start=0, count_neg=0, ans_len=0;
        //first neg stores the idx of first negative element of sliding window
        // start is starting of sliding window
        //count_neg keeps count of negative number
        //ans_len is our result

        //we have to exclude the '0' from the sliding window

        for(int i=0;i<n;i++){
            if(arr[i] == 0){
                //reinitialize
                first_neg = -1;
                start=i+1;
                count_neg = 0;
                continue;
            }else if(arr[i]<0){
                if(first_neg == -1){
                    first_neg=i;
                }
                count_neg++;
            }
            //even number of count means eventually it produces a positive number
                if(count_neg%2 == 0){
                    ans_len = max(ans_len, i-start+1);
                }else
                    ans_len = max(ans_len, i-first_neg);
                
            
        }
        return ans_len;
    }

};
