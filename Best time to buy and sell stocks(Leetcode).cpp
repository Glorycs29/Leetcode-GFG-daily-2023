class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result=0, minVal = INT_MAX;
        int soldToday = -1;
        for(int price: prices){
            minVal = min(price, minVal);
            soldToday = price-minVal;
            result = max(result, soldToday);
        }     
        return result;
    }

};
