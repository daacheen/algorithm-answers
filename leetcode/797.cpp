#include "cppincludes.h"

class Solution {
  public:
    void dfs(vector<vector<int>> &graph, int now, vector<int> &path,
             vector<vector<int>> &result) {
        if (now == graph.size() - 1) {
            result.push_back(path);
            return;
        }

        if (graph[now].size() == 0) {
            return;
        }

        for (int node : graph[now]) {
            path.push_back(node);
            dfs(graph, node, path, result);
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<int>> result;
        vector<int> path{0};

        dfs(graph, 0, path, result);
        return result;
    }
};