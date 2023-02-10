class Solution{
public:
    int maxInstance(string s){
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        return min({mp['b'], mp['a'], mp['l']/2, mp['o']/2, mp['n']});
        
    }
};
