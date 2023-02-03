 class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        vector<string> rows(numRows);
        int j = 0, d = 1;
        // j is the index to track which rows a character should be added to
        // d is the direction: -1 means go up, 1 means go down
        for (int i = 0; i < s.size(); i++) {
        // add the current character to corresponding row
            rows[j] += s[i];
            if(j == numRows - 1) d = -1;
        // if it reaches to the first row, we need to go down
            else if(j == 0) d = 1;
        // move j pointer
            j += d;
        }


// rows would look like below in the first example
        // ['PAHN', 'APLSIIG', 'YIR']
        // we use `accumulate` to build the final answer (in C++ 20, it takes O(n) only)
           return accumulate(rows.begin(), rows.end(), string{});


        // string res = "";
        // for(int i=0; i<numRows; i++){
        //     res += rows[i];
        // }

        // return res;
    }
};
