#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int node, vector<int> &path, vector<vector<int>> &graph){
        int n = graph.size();
        if (node == n-1){
            ans.push_back(path);
            return;
        }
        for (auto i : graph[node]){
            path.push_back(i);
            dfs(i, path, graph);
            // backtrack
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph){
        vector<int> path = {0};
        dfs(0, path, graph);
        return ans;
    }
};