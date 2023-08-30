#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dfs(vector<int>adj[],vector<bool> &visited,int node){
        int change = 0;
        visited[node] = true;
        for(auto it:adj[node]){
            if(!visited[abs(it)]){
                if(it > 0) change += dfs(adj,visited,it)+1;
                else change += dfs(adj,visited,abs(it));
            }
        }
        return change;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto c:connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(-c[0]);
        }
        vector<bool> visited(n,false);
        return dfs(adj,visited,0);
    }
};