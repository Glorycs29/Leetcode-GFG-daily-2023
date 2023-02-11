class Solution{
    public:
    bool isSubSequence(string a, string b) 
    {
        if(a.size()>b.size())return false;
        int j=0,i;
        for(int i=0;i<b.size() && j<a.size();i++){
            if(a[j]==b[i]) j++;
        }
        if(j==a.size())return true;
        else return false;
    }
}
