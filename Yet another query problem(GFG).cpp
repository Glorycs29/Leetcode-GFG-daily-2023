
class Solution{
  vector<int> solveQueries(int N, int num, vector<int> &a, vector<vector<int>> &Q) {
      map<int,int> freq;
      for(auto &x:a)
      freq[x]++;
      map<int, vector<int>> mp;
      for(int i=0;i<N;i++){
          mp[freq[a[i]]].push_back(i);
          freq[a[i]]--;
      }
      vector<int> ans;
      for(auto &x:Q){
          int l=x[0],r=x[1],k=x[2];
          vector<int> v(mp[k]);
          auto it1=lower_bound(v.begin(),v.end(),l);
          auto it2=upper_bound(v.begin(),v.end(),r);
          ans.push_back(it2-it1);
      }
      return ans;
  }
};
