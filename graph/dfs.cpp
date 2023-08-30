#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<int> &visited, int s)
{
    visited[s] = 1;
    for (int i = 0; i < adj[s].size(); i++)
    {
        if (visited[adj[s][i]] == 0)
        {
            dfs(adj, visited, adj[s][i]);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, e, a, b, connectedComponents = 0;
        cin >> n >> e;
        vector<int> adj[n + 1];
        for (int i = 0; i < e; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> visited(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                dfs(adj,visited, i);
                connectedComponents++;
            }
        }
        cout <<"connected components are : " << connectedComponents << endl;
    }
    return 0;
}