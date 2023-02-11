		
class Solution {
public:
    bool isSubsequence(string s, string t) {
        
    int j = 0; // For index of str1 (or subsequence
 
    // Traverse str2 and str1, and
    // compare current character
    // of str2 with first unmatched char
    // of str1, if matched
    // then move ahead in str1
    for (int i = 0; i < t.length() && j < s.length(); i++)
        if (s[j] == t[i])
            j++;
 
    // If all characters of str1 were found in str2
    return (j == s.length());
    }
};

//////////////////////////////////////////////////////////////////////

 // recursion // from the end

class Solution {
public:
    
    bool isSubs(string& s, string& t, int m, int n)
    {
        if(m == 0)
            return true;
        if(n == 0)
            return false;
        
        // If last characters of two
        // strings are matching
        if (s[m - 1] == t[n - 1])
            return isSubs(s, t, m - 1, n - 1);
 
        // If last characters are
        // not matching
        return isSubs(s, t, m, n - 1);
    }
    
    
    bool isSubsequence(string s, string t) {
        
       if( isSubs(s,t,s.length(),t.length()))
           return true;
        
        return false;
        
    }
};





//////////////////////////////////////////////////////////////////
 
// using dp // check for longest common subsequence is equals to m or not....
					
class Solution {
public:
    
    // returns the length of longest common subsequence
    int isSubs(string& s1, string& s2, int i , int j,vector<vector<int>> &t)
    {
        if(i == 0 || j == 0)
            return 0;
        if(t[i][j] != -1)
            return t[i][j];
        if(s1[i-1] == s2[j-1])
            return t[i][j] = 1 + isSubs(s1,s2,i-1,j-1,t);
        else
            return t[i][j] = isSubs(s1,s2,i,j-1,t);
    }
    
    
    bool isSubsequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        
        // intialising dp matrix with -1
        
        if(m >  n)
            return false;
        
        vector<vector<int>> t(m+1,vector<int> (n+1,-1));
    
        if(isSubs(s1,s2,m,n,t) == m)
            return true;
        return false;
    }
};
