// class Solution {

//   public:
//     int noConseBits(int n) {
        
//         // ans will store the required result 
//         // i is number use to iterate over number and check whether the ith bit is set or not
//         // count will store the number of consecutive ones 
//         int ans=0, i=31, count=0; 
//         while(i>=0){
            
//             if(count<=1 && (n&(1<<i))){
//                 ans = (ans | (1<<i));
//                 count++;
//             }else{
//                 count=0;
//             }
//             i--;
//         }
//         return ans;
//     }
// };

class Solution {

  public:
    int noConseBits(int n) {
        
        for(int i = 30; i>=2; i--)
        {
            int mask1 = 1<<i;
            int mask2 = 1<<(i-1);
            int mask3 = 1<<(i-2);
            
            if((mask1&n) && (mask2&n) && (mask3&n)){
                n = (n^mask3);
            }
        }
        return n;
    }
};
