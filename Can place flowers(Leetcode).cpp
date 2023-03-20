class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    // we need to find that how many maximum flowers can be planted 
        int size=flowerbed.size();
    // initialize the count of zero
        int zeroes=1, ans=0;
        if(n==0)return true;
        for(int i=0;i<size;i++){
            if(flowerbed[i]==0)++zeroes;
            else{
            // number of zeroes possible
                ans+= (zeroes-1)/2;
                zeroes=0;
            }
        }
        return ans+ (zeroes)/2 >=n;
    }

//     class Solution {
// public:
//     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//         if (n == 0) return true;
//         for (int i = 0; i < flowerbed.size(); i ++) {
//             if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) { // can place?
//                 -- n;
//                 if (n == 0) return true;
//                 flowerbed[i] = 1; // place!
//             }
//         }
//         return false;
//     }

};
