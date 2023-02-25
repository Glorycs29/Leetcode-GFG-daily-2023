class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mv = INT_MAX;
        // for( auto x : nums){
        //     pq.push(x*2);
        //     mv = min(x, mv);
        // }
        for( int x : nums){
            if( x%2==0){
                pq.push(x);
                mv = min( mv, x);
            }
            else {
                pq.push(x*2);
                mv= min( mv, x*2);
            }
        }
        
        int ans = INT_MAX;
        while( !pq.empty()){
            int top = pq.top();
            pq.pop();
            ans = min( ans, top - mv);
            if( top%2!=0)break;
            pq.push(top/2);
            mv = min( mv, top/2);
        }
        return ans;
    }
};
