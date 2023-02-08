class Solution{
public:

	void rearrange(int arr[], int n) {
	   vector<int> pos,neg;
	   
	   for(int i=n-1;i>=0;i--){
	       
	       if(arr[i]>=0){
	           pos.push_back(arr[i]);
	       }else{
	           neg.push_back(arr[i]);
	       }
	   }
	   
	   int i=0;
	   while(i<n){
	       
	       if(!pos.empty()){
	           arr[i++]=pos.back();
	           pos.pop_back();
	       }
	       
	       if(!neg.empty()){
	           arr[i++]=neg.back();
	           neg.pop_back();
	       }
	   }
	   
	}
};
