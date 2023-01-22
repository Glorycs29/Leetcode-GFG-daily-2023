#include <bits/stdc++.h>

using namespace std;

#define int long long

#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL)
#define endl '\n'

const int mod = 1e9 + 7;




void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	
	for(int &i: a) cin >> i;
	for(int &i: b) cin >> i;
	
	vector<pair<int, int>> vec;
	for(int i = 0; i < n; i++)
		vec.push_back({min(a[i], b[i]), max(a[i], b[i])});
	
	sort(vec.begin(), vec.end());
	
	multiset<int> ms;
	for(int i = 0; i < n; i++)
		ms.insert(vec[i].first);
	
	int res = *(ms.rbegin()) - *(ms.begin());
	for(int i = 0; i < n; i++){
		ms.erase(vec[i].first);
		ms.insert(vec[i].second);
		res = min(res, *(ms.rbegin()) - *(ms.begin()));
	}
	
	cout << res << endl;
	
	
}

signed main() {
    fast();
	int t = 1;
	cin >> t;
	while(t--){
        solve();
    }
	return 0;
}

/*

Explanation of the code by murugank0204
Code implementation
From Line 16 to 21
Receive inputs

Code implementation
From Line 23 to 25
Swap the pairs if needed, such that a[i] <= b[i] for all i.

Code implementation
Line 27
sorting the array, based on a[i].

The intuition behind this, after sorting we can surely say that,

a[0] is the minimum and a[n-1] is the maximum.

Approach
Line 29
Used multiset (You can use any Data Structure, in which insertion, deletion, finding the maximum and minimum element at O(1) time, constant time. Eg: ordered set, set with indexing, map, etc.

Code implementation
From Line 30 to 31
Inserting all the values of a[i] to multiset. Note that, we have already swapped the indexes, such that a[i] <= b[i]

Code implementation
From Line 33 to 38
Note that:

a[i] <= b[i] (we swapped already)
a[i] <= a[i + 1] (we sorted the array already)
Traversing the array, we swap one by one, from index 0, while updating the multiset simultaneously. and getting the minimum and maximum elements.

while traversing we erase the a[i] as it goes down, and inserting the b[i] as it was coming up.

*/




