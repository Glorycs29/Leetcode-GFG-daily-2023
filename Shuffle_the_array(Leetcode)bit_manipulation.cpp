class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i=0;i<n;i++){
            //to combine the number //in a single number
            //left shift by 10 bits
            nums[i]=nums[i]<<10;
            nums[i]=nums[i] | nums[i+n];
        }
        int j=2*n-1;
        for(int i=n-1; i>-1;i--,j=j-2){
            //right shift to extract the starting 10 bits
            int x=nums[i]>>10;
            // taking and with 1023 to get the number of 10 bit
            int y=nums[i]&((1024)-1);
            nums[j]=y;
            nums[j-1]=x;
        }
        return nums;
    }
};
