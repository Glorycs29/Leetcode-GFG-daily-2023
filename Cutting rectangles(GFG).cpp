class Solution{
public:
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        long long int ans=1, k=1;
        k=__gcd(L,B);
        ans= L/k*B/k;
        return {ans,k};
    }
};
