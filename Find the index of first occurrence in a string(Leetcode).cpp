class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(), m=needle.size();
        int ans=-1, k=0;
    // first target is to find out the index of first ocurrence of first index of needle.

        while(k<n){
            auto itr = find(haystack.begin()+k, haystack.end(), needle[0]);
    // after getting first index, search whether the substring of size needle in haystack is equals to needle or not ?
            int idx = itr - haystack.begin();
            string str = haystack.substr(k, m); // (from idx, size of sbustr)
            if(str==needle){
                ans=idx;
                return idx;
            }else{
                k=k+1;
                continue;
            }
        }
        return ans;
    }
};
