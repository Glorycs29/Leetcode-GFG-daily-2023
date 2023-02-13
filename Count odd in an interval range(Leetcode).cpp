class Solution {
public:
    int countOdds(int low, int high) {
        if((low%2 == 0 && high%2 != 0) || (low%2 != 0 && high%2 == 0)){
            return (high - low + 1)/2;
        }
        else if(low%2 != 0 && high %2 != 0){
            return (high - low)/2 + 1;
        }
        else{
            return (high - low)/2;
        }
    }
};

//////////////////////////////////////////////////////////

class Solution {
public:
    int countOdds(int low, int high) {
        int cntOdd=0;
        for(int i=low;i<=high;i++){
            if(i & 1 !=0)cntOdd++;
        }
        return cntOdd;
    }
};
