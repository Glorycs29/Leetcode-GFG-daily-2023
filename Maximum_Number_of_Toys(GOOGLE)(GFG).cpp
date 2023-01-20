// Approach to solve this problem:

// 1. As we need to find maximum number of toys that we can buy with a given amount. It's always preferable to go for toys with lowest cost.

// Hence, we sort the array and start buying from index 1 to N till the money left is more than the cost of current toy.
// This step takes O(N) time. We can do it in O(logN) using prefix and binary search.

// 2. As each query gives the indices of toys that are broken, and sorting will disturb the original indices, we need to store the original index with the cost.
// Hence, we create an array of pair<int,int> to store cost and index.
// Then we sort the new array.

// 3. Now, when we purchase from index 0 to N-1 of sorted array untill the money is left, there are two cases, either we encounter the broken toys indices or we don't.
// We need a quick way to check where in the sorted array lies the broken toy.
// Hence, we create a map<int,int> from original index to sorted index.
// If broken toy's index in sorted array is after the last toy we purchase, we need not do anything.
// But, if broken toy's index in sorted array is equal to of less than the last index of purchase. Then we remove that toy from our purchase and add the cost in our remaining money.
// Now, the remaining money can we used to purchase other toys. And, as we have already gone through all the indices till last purchase, we only have check if we can buy the toys after that.
// Condition to check, cost<= remaining money and index!=broken toy's index.

// That's it, we store the solution for current query in a vector and return the vector.


using ll = long long;
class Solution{
public:
  vector<int> maximumToys(int N,vector<int> A,int Q,vector<vector<int>> Queries){
      // code here
      // creating an array of pair for cost and index. Then sorting.
      vector<pair<int,int>> arr(N);
      for(int i=0; i<N; i++) arr[i] = {A[i],i};
      
      sort(arr.begin(),arr.end());
      
// creating a map for original index to new sorted index
      map<int,int> mp;
      for(int i=0; i<N; i++)
      {
          mp[arr[i].second] = i;
      }
      
// prefix sum and binary search for maximum toys we can buy
      vector<ll> prefix(N+1);
      prefix[0] = 0;
      for(int i=1; i<=N; i++)
      {
          prefix[i] = prefix[i-1] + arr[i-1].first;
      }
      
// result vector for Q queries
      vector<int> res(Q);
      
      for(int i=0; i<Q; i++)
      {
          ll c = Queries[i][0];
          int k = Queries[i][1];
          
          int l = 0;
          int r = N;
          int ans = 0;
          while(l<=r)
          {
              int mid = l + (r-l)/2;
              
              if(prefix[mid]<=c)
              {
                  ans = mid;
                  l = mid+1;
              }
              else r = mid-1;
          }
          

          if(ans <= 0)
          {
              res[i] = 0;
              continue;
          }

// index of last purchase, idx is ans-1 (0 based indexing used).
          int idx = ans-1;

// remaining money, rem
          ll rem = c - prefix[ans];
          
// set notRemoved to check if toys are broken after idx, when we try to purchase with remaining money

          set<int> notRemoved;
         
// checking for all k toys
          for(int j = 0; j<k; j++)
          {
// qIdx gives the index of broken toy in sorted array
              int qIdx = mp[Queries[i][j+2] - 1];
              if(qIdx<=idx)
              {
                  ans--;
                  rem += arr[qIdx].first;
              }
              else notRemoved.insert(qIdx);
          }
          
// purchasing with remaining money
          int s = idx+1;
          while(s<N && arr[s].first<=rem)
          {
              if(!notRemoved.count(s))
              {
                  ans++;
                  rem-=arr[s].first;
                  
              }
              s++;
          }
          
// storying the ans in res vector
          res[i] = ans;
          
          
      }
      
      return res;
  }
};
