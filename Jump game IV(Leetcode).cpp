class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> graph(n);
        unordered_map<int, vector<int>> sameVals;

        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0) {
                graph[i].emplace_back(i - 1);
            }

            if (i + 1 < n) { 
                graph[i].emplace_back(i + 1);
            }

            sameVals[arr[i]].emplace_back(i);
        }

        queue<int> q;
        set<int> visited;
        q.push(0);
        visited.insert(0);
        int cnt = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int top = q.front();
                q.pop();
                if (top == n - 1) {
                    return cnt;
                }
                for (auto neigh:graph[top]) {
                    if (visited.find(neigh) == visited.end()) {
                        q.push(neigh);
                        visited.insert(neigh);
                    }
                }

                for (auto neigh:sameVals[arr[top]]) {
                    if (visited.find(neigh) == visited.end()) {
                        q.push(neigh);
                        visited.insert(neigh);
                    }
                }

                sameVals[arr[top]].clear();
            }
            cnt++;
        }

        return -1;    
    }
};
