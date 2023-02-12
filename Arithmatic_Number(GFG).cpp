class Solution{
public:
    int inSequence(int a, int b, int c){
       if(c==0)return a==b;
       if(((b-a)%c)==0) return ((b-a)/c>=0);
       return false;
    }
};
