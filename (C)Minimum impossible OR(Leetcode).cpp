class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int mask = 0; 
        for (auto& x : nums) 
            if ((x & x-1) == 0) mask |= x; 
        for (int i = 0; i < 32; ++i) 
            if ((mask & 1<<i) == 0) return 1<<i; 
        return -1; 
    }
};


///
class Solution {
public:
    
    int minImpossibleOR(vector<int>& v) {
        map<int,int>m;
        for(int i=0;i<v.size();i++) m[v[i]]++;
        int num=1;
        while(true){
            if(m.find(num)==m.end()) return num;
            num=num*2;
        }
        return num;
    }

};
