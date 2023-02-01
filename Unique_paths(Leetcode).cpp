// this is purely based on mathematics
class Solution {
public:
    int uniquePaths(int m, int n) {
        double ans=1; // total steps will be m+n-2;
        // finding nCr of (total steps)C(min(n-1,m-1))
        for(int i=1; i<min(n,m); i++){
            ans = ans*(n+m-i-1)/i;
        }
        return (int)ans;
    }
};
