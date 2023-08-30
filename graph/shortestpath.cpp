#include <bits/stdc++.h>
using namespace std;

// void bfs(vector<int> adj[], vector<int>&distance, vector<bool>&vis, int s)
// {
//     queue<int> q;
//     q.push(s);
//     distance[s] = 0;
//     vis[s] = true;
//     while (!q.empty())
//     {
//         int p = q.front();
//         q.pop();
//         for (int i = 0; i < adj[p].size(); i++)
//         {
//             if (vis[adj[p][i]] == false)
//             {
//                 // incrementing distance of each node
//                 distance[adj[p][i]] = distance[p] + 1;
//                 q.push(adj[p][i]);
//                 vis[adj[p][i]] = true;
//             }
//         }
//     }
// }

// int main()
// {
//     int nodes,edges;
//     cin>>nodes>>edges;
//     int u,v;
//     vector<int> adj[nodes+1];

//     for(int i=0;i<edges;i++){
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<int> distance(nodes+1,0);    // distance of each node or ditance from source node
//     vector<bool>vis(nodes+1,false);

//     bfs(adj,distance,vis,0);
//     for(int i=0;i<nodes;i++){
//         cout<<distance[i]<<" ";
//     }

//     return 0;
// }

// printing shortest path 
vector<int> shortest_path(vector<int> adj[], vector<bool> &visited, int nodes, int s, int t)
{
    vector<int> parent(nodes+1,0);

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for (int i = 0; i < adj[p].size(); i++)
        {
            if (!visited[adj[p][i]])
            {
                q.push(adj[p][i]);
                visited[adj[p][i]] = true;
                parent[adj[p][i]] = p;
            }
        }
    }
    vector<int> ans;
    int currnode = t;
    ans.push_back(currnode);

    while (currnode != s)
    {
        currnode = parent[currnode];
        ans.push_back(currnode);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> adj[nodes + 1];
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(nodes + 1, false);

    cout<<"enter source and last node"<<endl;
    int s, t;
    cin >> s >> t;

    vector<int> result = shortest_path(adj, visited, nodes, s, t);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
