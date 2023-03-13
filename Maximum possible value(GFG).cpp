class Solution {
  public:
    long long maxPossibleValue(int n,vector<int> a, vector<int> b) {
        long long perimeter=0;    // 2*pair_count*value
        int count_pair=0;         // count of total pair 
        int exclude_mini=INT_MAX; // in case any pair will not contribute in making rectangle/square
        // now loop over array
        
        for(int i=0;i<n;i++){
            // if vaalue is greater than one then only paair is possible
            if(b[i]>1){
                perimeter+= 2*(b[i]/2)*a[i];
                count_pair+= b[i]/2;
                exclude_mini= min(exclude_mini, a[i]);
            }
        }
        
        if(count_pair%2!=0){
            perimeter-=2*exclude_mini;
        }
        return perimeter;
        
    }
};
