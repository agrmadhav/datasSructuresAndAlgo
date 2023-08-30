#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V];
        int indegree[V] = {0};
        for(int i=0;i<V;i++){
            // i->j tha initially
            // hamein j se i chayie
            for(auto j:adj[i]){
                adjRev[j].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>safenode;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safenode.push_back(node);
            for(auto i:adjRev[node]){
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        sort(safenode.begin(),safenode.end());
        return safenode;
    }
};