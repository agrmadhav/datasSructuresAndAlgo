// bridge ek aisi edge jisko remove krne se number of components increrase ho jaaye
#include <bits/stdc++.h>
using namespace std;
// Tarjan's Algorithm
class Solution
{
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &visited, vector<int> adj[],
             int timeInserted[], int lowestTime[], vector<vector<int>> &bridges)
    {
        visited[node] = 1;
        lowestTime[node] = timeInserted[node] = timer;
        timer++;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!visited[it])
            {
                dfs(it, node, visited, adj, timeInserted, lowestTime, bridges);
                lowestTime[node] = min(lowestTime[node], lowestTime[it]);
                if (lowestTime[it] > timeInserted[node])
                {
                    bridges.push_back({it, node});
                }
            }
            else
            {
                lowestTime[node] = min(lowestTime[node], lowestTime[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (auto i : connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> visited(n, 0);
        int timeInserted[n];
        int lowestTime[n];
        vector<vector<int>> bridges;
        dfs(0, -1, visited, adj, timeInserted, lowestTime, bridges);
        return bridges;
    }
};