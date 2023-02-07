class Solution{
    public:
    int search(int arr[], int s, int e, int target){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        while(s<=e){
            int mid=(e-s)/2+s;
            
            if(target==arr[mid])return mid;
            
            if(arr[mid]>=arr[s]){
                
                if(arr[mid] > target && arr[s]<=target){
                    e=mid-1;
                }else{
                    s=mid+1;
                }
                
            }else{
                
                if(target > arr[mid] && target<=arr[e]){
                    s=mid+1;
                }else{
                    e=mid-1;
                }
            }
            
        }
        return -1;
    }
};
