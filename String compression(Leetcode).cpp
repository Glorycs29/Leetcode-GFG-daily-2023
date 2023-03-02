 class Solution {
public:
    int compress(vector<char>& chars) {
        int low = 1, groupStartLoc = 0;
        for (int high = 1; high < (int)chars.size() + 1; high++) {
            if (high == (int)chars.size()
               || chars[high] != chars[low - 1]) {
                int cnt = (high - groupStartLoc);
                groupStartLoc = high;
                if (cnt > 1) {
                    for (auto ch:to_string(cnt)) {
                        chars[low++] = ch;
                    }
                }
                if (high < (int)chars.size()) {
                    chars[low++] = chars[high];
                }
            }
        }
        return low;
    }
};
