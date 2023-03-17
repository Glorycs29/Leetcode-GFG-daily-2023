long long int no_of_subarrays(int n, vector<int> &arr) {
    // Initialize count of subarrays of 0's to 0
    // Initialize count of zeroes to -
    long long count=0, zeroes=0;
    
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            zeroes++;
        }else{
            // if it is one calculate the no. of subarray and add it  
            // and make zeroes=0
            count+=(zeroes*(zeroes+1))/2;
            zeroes=0;
        }
    }
    
    // adding count of subarrays of 0's that end at last index seperately
    count+=(zeroes*(zeroes+1))/2;
    return count;
    
}
