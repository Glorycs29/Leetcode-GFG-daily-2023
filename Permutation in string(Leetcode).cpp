class Solution {
    bool areVectorsEqual(vector<int> a, vector<int> b){
        for(int i=0; i<26; i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        vector<int> freqS1(26, 0);
        for(char c: s1) freqS1[c-'a']++;
        
        vector<int> freqS2(26, 0);
        int i=0, j=0;
        
        while(j<s2.size()){
            freqS2[s2[j]-'a']++;
            
            if(j-i+1==s1.size()){
                if(areVectorsEqual(freqS1, freqS2)) return true;
            }
            
            if(j-i+1<s1.size()) j++;
            else{
                freqS2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};


// approach 2 

// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         int n1=s1.size();
//         int n2=s2.size();
//         if(n1>n2)return false;

//          sort(s1.begin(),s1.end());

//          for(int i=0;i<n2-n1+1;i++){
//         //     //take substring of size n1 from s2 string staring from i to n1 length
//              string str=s2.substr(i,n1);
//              //now sort the substring
//              sort(str.begin(),str.end());

//              if(str==s1){
//                  return true;
//              }
//          }
//          return false;
//     }

// };

// https://leetcode.com/problems/permutation-in-string/solutions/1762469/c-sliding-window-optimized-well-explained/?orderBy=most_votes
