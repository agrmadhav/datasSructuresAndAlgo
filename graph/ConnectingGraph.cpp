#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
            // path compression by using backtracking
        return parent[node] = findUPar(parent[node]); 
    }
    // much more intutuive than union by rank
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 

        if(ulp_u == ulp_v) return; 

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }

        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdge = 0;
        for(auto it:connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v)){
                extraEdge++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int cntConnected = 0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i) == i){
                cntConnected++;
            }
        }
        if(extraEdge >= cntConnected-1) return cntConnected-1;
        return -1;
    }
};