#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &visited, stack<int> &topo, vector<pair<int, int>> adj[])
{
    visited[node] = 1;

    for (auto i : adj[node])
    {
        if (!visited[i.first])
        {
            dfs(i.first, visited, topo, adj);
        }
    }
    topo.push(node); // to store it in a stack so we can get a topological sort
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<pair<int, int>> adj[nodes + 1]; // in pair at first position node is stored and in second weight is stored
    int u, v, wt;
    cout<<"enter all the possible nodes"<<endl;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    // try to check adj list by printing it
    // for(int i=0;i<nodes;i++){
    //     for(pair<int,int>p : adj[i]){
    //         int vertex = p.first;
    //         int weight = p.second;
    //         cout<<i<<" -> ("<<vertex<<","<<weight<<") ";
    //     }
    //     cout<<endl;
    // }
    vector<int> visited(nodes + 1, 0);

    stack<int> topo;

    // topological sort

    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, topo, adj);
        }
    }

    int src;
    cout<<"enter source node"<<endl;
    cin>>src;
    vector<int> distance(nodes, INT32_MAX);
    distance[src] = 0;

    while (!topo.empty())
    {
        int top = topo.top();
        topo.pop();

        if (distance[top] != INT32_MAX)
        {
            // for(auto i:adj[top]){
            //     if(distance[top] + i.second < distance[i.first]){
            //         distance[i.first] = distance[top] + i.second;
            //     }
            // }

            for (int i = 0; i < adj[top].size(); i++)
            {
                int adjvertex = adj[top][i].first;
                int weight = adj[top][i].second;
                if (distance[top] + weight < distance[adjvertex])
                {
                    distance[adjvertex] = distance[top] + weight;
                }
            }
        }
    }
    cout<<"the shortest path from node "<<src<<" is : "<<endl;
    for (int i = 0; i < distance.size(); i++)
    {
        cout << distance[i] << " ";
    }

    return 0;
}


    //  vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    //     vector<pair<int,int>> adj[N];
    //     for(int i=0;i<M;i++){
    //         int u = edges[i][0];
    //         int v = edges[i][1];
    //         int wt = edges[i][2];
    //         adj[u].push_back({v,wt});
    //     }