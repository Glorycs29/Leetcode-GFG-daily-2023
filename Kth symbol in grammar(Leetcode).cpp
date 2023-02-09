class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 && k==1){
            return 0;
        }

        if(n==2 && k==1)return 0;
        else if(n==2 && k==2)return 1;
        if(k<=(pow(2,n-2))) return kthGrammar(n-1,k);
        int y=pow(2,n-2);
        int x=k%y;
        if(x==0) x=pow(2,n-2);
        return !kthGrammar(n-1,x);
    }
};
