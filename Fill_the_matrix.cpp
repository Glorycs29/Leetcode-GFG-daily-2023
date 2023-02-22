class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        
         if (N == 1 && M == 1)
        {
            return 0;
        }
        int ans = 0;
        int X = x - 1;
        int Y = y - 1;
        // top left 
        ans = max(ans,X + Y);
        // bottom left
        ans = max(ans,(N - (X + 1)) + Y);
        // top right
        ans = max(ans,X + (M - (Y + 1)));
        // bottom right
        ans = max(ans,(N - (X + 1)) + (M - (Y + 1)));
        return ans;
    }

};
