class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>ans;
        int i = num.size()-1;
        while(k && i >= 0){
            num[i] += k % 10;
            k /= 10;
            if(num[i] > 9){
                ans.push_back(num[i] - 10);
                k++;
            }
            else
                ans.push_back(num[i]);
            i--;
        }
        while(i >= 0){
            ans.push_back(num[i--]);
        }
        while(k){
            ans.push_back(k % 10);
            k /= 10;
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
