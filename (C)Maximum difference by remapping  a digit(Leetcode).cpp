class Solution {
public:
    int minMaxDifference(int num) {
        string s1= to_string(num);
        string s2=to_string(num);
        char c=s1[0],ch=s1[0];
        // setting first dig as 9
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!='9'){
                c=s1[i];
                break;
            }
        }
        
        for(int i=0; i<s1.size(); i++){
            if(s1[i]==c) s1[i]='9';
        }
        for(int i=0; i<s1.size(); i++){
            if(s2[i]==ch) s2[i]='0';
        }
        int mx=stoi(s1),mn=stoi(s2);
        return mx-mn;
    }
};


//efficient solution


class Solution {
public:
    int findBug(int num) {
        
        int maxi=INT_MIN,mini=INT_MAX;
        
        string s=to_string(num);
        
        for(int i=0;i<10;i++)
        {
            string s1=s,s2=s;
            
            for(auto &x:s1)
            {
                if(x==i+'0')
                {
                    x='9';
                }
            }
            
            for(auto &x:s2)
            {
                if(x==i+'0')
                {
                    x='0';
                }
            }
            
            maxi=max(maxi,stoi(s1));
            mini=min(mini,stoi(s2));
        }
        
        return maxi-mini;
    }
};
