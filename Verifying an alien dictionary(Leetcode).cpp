unordered_map<char,int> mp;
class Solution {
private:
    bool static cmp(string a, string b){
        // traverse upto the length of shorter string
        int n= min(a.length(), b.length());
        for(int i=0;i<n;i++){
            if(mp[a[i]] < mp[b[i]]){
                return true;
            }else if(mp[a[i]] > mp[b[i]]){
                return false;
            }
        }

        // now if length of a is still remaning then definetly false
        if(a.length() <= b.length()){
            return true;
        }else{
            return false;
        }
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // create an unordered_map to store the ordering of alien dictionary
        // create a temp vector and store words in it..
        // sort it according to alien dictionary and match it with words

        for(int i=0;i<order.size();i++){
            mp[order[i]]=i;
        }

        vector<string> temp = words;
        sort(temp.begin(), temp.end(),cmp);
        return temp==words;
    }
};
