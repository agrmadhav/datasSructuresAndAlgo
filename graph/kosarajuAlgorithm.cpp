#include <bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int> &topo, vector<int> &vis, vector<vector<int>> &adj){
    vis[node] = 1;
    for (auto it : adj[node]){
        if (!vis[it]){
            dfs(it, topo, vis, adj);
        }
    }

    topo.push(node);
}
void revDfs(int node, vector<int> &vis, vector<vector<int>> transpose, vector<int> &component){
    vis[node] = 1;
    component.push_back(node);
    for (auto it : transpose[node]){
        if (!vis[it])
            revDfs(it, vis, transpose, component);
    }
}
vector<vector<int>> findSCCs(int n, vector<vector<int>> &adj){
    // Step-1:Find topo order
    stack<int> topo;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++){
        if (!vis[i])
            dfs(i, topo, vis, adj);
    }

    // Step 2:Making transpose of graph
    vector<vector<int>> transpose;

    for (int i = 0; i < n; i++){
        vis[i] = 0;
        for (auto it : adj[i]){
            transpose[it].push_back(i);
        }
    }

    // Step 3: DFS on transpose in topological order
    vector<vector<int>> SCCs;
    while (!topo.empty()){
        int node = topo.top();
        topo.pop();
        if (!vis[node]){
            vector<int> component;
            component.clear();
            revDfs(node, vis, transpose, component);
            SCCs.push_back(component);
        }
    }

    return SCCs;
}