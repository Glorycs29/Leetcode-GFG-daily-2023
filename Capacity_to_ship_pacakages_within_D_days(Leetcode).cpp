class Solution {
public:
    int noOfDaysToShip(vector<int>& weights, int capacity) {
        int days = 1, curLoad = 0;
        for (auto w:weights) {
            curLoad += w;
            if (curLoad > capacity) {
                curLoad = w;
                days++;
            }
        }
        return days;
    }
 
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = -1;
        
        int l = *max_element(weights.begin(), weights.end()); 
        int r = accumulate(weights.begin(), weights.end(), 0);
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (noOfDaysToShip(weights, mid) <= days) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
