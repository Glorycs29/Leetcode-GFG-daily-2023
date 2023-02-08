int findElement(int arr[], int n) {
    int ans=-1;
    int big= arr[0];
    int small = arr[n-1];
    int maxi[n]; // left side arr
    int mini[n]; // right side arr
    
    for(int i = 1;i < n;i++){
        if(arr[i] > big)
            big = arr[i];
        
        maxi[i] = big;
        
    }
    
    for(int i = n-2;i >= 0;i--){
        if(arr[i]<small)
            small = arr[i];
        
        mini[i] = small;
        
    }
    
    for(int i=0;i<n;i++){
        if(maxi[i]==mini[i]){
            ans=maxi[i];
            break;
        }
    }
    return ans;
}
