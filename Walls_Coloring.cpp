class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int n) {
        int Ai_1 = colors[0][0], Bi_1 = colors[0][1], Ci_1 = colors[0][2];

        for(int i = 1; i< n; i++){

            int t1 = colors[i][0] + min(Bi_1, Ci_1);

            int t2 = colors[i][1] + min(Ai_1, Ci_1);

            int t3 = colors[i][2] + min(Bi_1, Ai_1);

            Ai_1 = t1, Bi_1 = t2, Ci_1 = t3;

        }

        return min(Ai_1, min(Bi_1, Ci_1));

    }

};
