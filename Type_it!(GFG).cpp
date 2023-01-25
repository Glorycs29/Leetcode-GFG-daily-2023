class Solution {
  public:
    int minOperation(string s) {
        int n=s.length()-1;
        int op=0;
        bool appended=false;
        while(n>=0)
        {
            int currlen=n+1;
            if(!appended && currlen%2==0 && s.substr(0,currlen/2)==s.substr(currlen/2,currlen/2))
            {
                n-=(currlen/2);
                appended=true;
            }
            else
            {
                n--;
            }
            op++;
        }
        return op;
    }
};
