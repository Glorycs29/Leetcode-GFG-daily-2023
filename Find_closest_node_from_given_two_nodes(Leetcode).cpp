class Solution {
public:
    // helper function to perform depth first search
    void dfs(int node, int dist, vector<int> edges, vector<int>& dis) {
        // iterate until we reach the end of the edge or a node that has already been visited
        while (node != -1 && dis[node] == -1) {
            dis[node] = dist++; // update distance of current node
            node = edges[node]; // move to next node
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int res = -1, min_dist = INT_MAX, n = edges.size();
        // create distance vectors for both nodes
        vector<int> dist1(n, -1), dist2(n, -1);
        // perform DFS starting from node1 and node2
        dfs(node1, 0, edges, dist1);
        dfs(node2, 0, edges, dist2);

        // iterate through all nodes
        for (int i = 0; i < n; ++i) {
            // check if current node is the closest meeting point
            if (min(dist1[i], dist2[i]) >= 0 && max(dist1[i], dist2[i]) < min_dist) {
                min_dist = max(dist1[i], dist2[i]);
                res = i;
            }
        }
        return res;
    }
};
