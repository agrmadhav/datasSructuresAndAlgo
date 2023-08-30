// to find minimum spanning tree

// spanning tree convert graph into tree such that it has n nodes and n-1 edges and each nodes can be accesed by any nodes

// for minimum spanning tree means minimum cost of weights

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"enter number of nodes and edges"<<endl;
    int nodes, edges;
    cin >> nodes >> edges;
    vector<pair<int, int>> adj[nodes];
    cout<<"enter all the edges with weight"<<endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int>visited(nodes,0);
    vector<int>parent(nodes,-1);
    vector<int>key(nodes,INT32_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int src;
    cout<<"enter the source node"<<endl;
    cin>>src;

    pq.push({0,src});
    key[src] = 0;
    // int sum = 0;

    while(!pq.empty()){
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(visited[node]== 1){
            continue;
        }
        visited[node] = 1;
        // sum = sum+cost;

        for(auto i:adj[node]){
            int adjnode = i.first;
            int weight = i.second;

            if(!visited[adjnode] && key[adjnode]>weight){
                key[adjnode] = weight;
                pq.push({weight,adjnode});
                parent[adjnode] = node;
            }
        }
    }

    // cout<<sum<<endl;
    cout<<"mst of the graph has following edges"<<endl;
    for(int i=1;i<parent.size();i++){
        cout<<parent[i]<<" - "<<i<<" with weight "<<key[i]<<endl;
    }

    int res = 0;
    for(int i=0;i<key.size();i++){
        res+=key[i];
    }
    cout<<"weight of the mst is "<<res<<endl;
    return 0;
}