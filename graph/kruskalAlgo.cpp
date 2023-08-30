// disjoint set
/*
suppose graph has multiple components
if we have two nodes and we have to find wheter they belong to same component or not we can find by disjoint set
2 major operation : findparent or findset and union or unionset

efficient approach union by rank and path compression

if rank same koi bhi parent ho skta hai dono mai se

agr kisi ki rank jyada hai toh whi parent hoga

ham short tree ko long tree mai merge krte hai takki depth tree ki kam rhe

*/
#include <bits/stdc++.h>
using namespace std;

// void makeset(vector<int>&parent, vector<int>&rank, int nodes){
//     // for initialising parent and rank array
//     for(int i=0;i<nodes;i++){
//         parent[i] = i;
//         rank[i] = 0;
//     }
// }

// int findParent(vector<int>&parent,int node){
//     if(parent[node] == node){
//         return node;
//     }
//     // return findParent(parent,parent[node]);
//     // for path compression below procedure
//     parent[node] == findParent(parent,parent[node]);
//     return parent[node];
// }

// void UnionSet(vector<int>&parent,vector<int>&rank,int u,int v){
//     // for union first we have find parent of u and v and also rank of it
//     u = findParent(parent,u);
//     v = findParent(parent,v);

//     if(rank[u]>rank[v]){
//         parent[v] = u;
//         rank[u]+=rank[v];
//     }
//     else if(rank[u]<rank[v]){
//         parent[u] = v;
//         rank[v]+=rank[u];
//     }
// }

// int main()
// {
//     int nodes,edges;
//     cin>>nodes>>edges;

//     vector<int>parent(nodes);
//     vector<int>rank(nodes);
//     makeset(parent,rank,nodes);

//     pair<long long,pair<int,int>> p[nodes];

//     for(int i=0;i<edges;i++){
//         int u,v,weight;
//         cin>>u>>v>>weight;
//         p[i] = make_pair(weight,make_pair(u,v));
//     }

//     // sort edges in ascending order
//     long long minimumCost = 0;
//     sort(p,p+edges);

//     int u,v;
//     long long cost;

//     for(int i=0;i<edges;i++){
//         u = p[i].second.first;
//         v = p[i].second.second;
//         cost = p[i].first;

//         if(findParent(parent,u) != findParent(parent,v)){
//             minimumCost += cost;
//             UnionSet(parent,rank,u,v);
//         }
//     }

//     cout<<minimumCost<<endl;

//     return 0;
// }

// hackerearth tutorial
//  #include <iostream>
//  #include <vector>
//  #include <utility>
//  #include <algorithm>

// using namespace std;
// const int MAX = 1e4 + 5;
// int parent[MAX], nodes, edges;
// pair <long long, pair<int, int> > p[MAX];

// void initialize()
// {
//     for(int i = 0;i < MAX;i++)
//         parent[i] = i;
// }

// int findParent(int x)
// {
//     while(parent[x] != x)
//     {
//         parent[x] = parent[parent[x]];
//         x = parent[x];
//     }
//     return x;
// }

// void union1(int x, int y)
// {
//     int p = findParent(x);
//     int q = findParent(y);
//     parent[p] = parent[q];
// }

// long long kruskal(pair<long long, pair<int, int> > p[])
// {
//     int x, y;
//     long long cost, minimumCost = 0;
//     for(int i = 0;i < edges;i++)
//     {
//         // Selecting edges one by one in increasing order from the beginning
//         x = p[i].second.first;
//         y = p[i].second.second;
//         cost = p[i].first;
//         // Check if the selected edge is creating a cycle or not
//         if(findParent(x) != findParent(y))
//         {
//             minimumCost += cost;
//             union1(x, y);
//         }
//     }
//     return minimumCost;
// }

// int main()
// {
//     int x, y;
//     long long weight, cost, minimumCost;
//     initialize();
//     cin >> nodes >> edges;
//     for(int i = 0;i < edges;++i)
//     {
//         cin >> x >> y >> weight;
//         p[i] = make_pair(weight, make_pair(x, y));
//     }
//     // Sort the edges in the ascending order
//     sort(p, p + edges);
//     minimumCost = kruskal(p);
//     cout << minimumCost << endl;
//     return 0;
// }

// codeforces
struct node
{
    int u, v, wt;
    node(int first, int second, int weight)
    {
        u = first, v = second, wt = weight;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findParent(int u, vector<int> &parent)
{
    if (parent[u] == u)
        return u;
    return parent[u] = findParent(parent[u], parent);
}

void union_set(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
        rank[u] += rank[v];
    }

    else
    {
        parent[v] = u;
        rank[v] += rank[u];
    }
}

int main()
{
    int nodes, m;
    cin >> nodes >> m;
    vector<node> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(nodes);
    for (int i = 0; i < nodes; i++)
        parent[i] = i;

    vector<int> rank(nodes, 1);

    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto it : edges)
    {
        if (findParent(it.v, parent) != findParent(it.u, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            union_set(it.u, it.v, parent, rank);
        }
    }
    cout << cost << endl;
    for (auto it : mst)
        cout << it.first << " - " << it.second << endl;
    return 0;
}

// submited in gfg
class DisjointSet {
    vector<int>parent, size; 
public: 
    DisjointSet(int n) {
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
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjnode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt,{node,adjnode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int mstweight = 0;
        for(auto i:edges){
            int wt = i.first;
            int u = i.second.first;
            int v = i.second.second;
            if(ds.findUPar(u) != ds.findUPar(v)){
                mstweight += wt;
                ds.unionBySize(u,v);
            }
        }
        return mstweight;
    }
};