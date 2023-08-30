// using priority queue

#include<bits/stdc++.h>
using namespace std;

int main(){
    int nodes,edges;
    cin>>nodes>>edges;

    vector<pair<int,int>>adj[nodes+1];

    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>visited(nodes+1,0);
    vector<int>distance(nodes+1,1e9);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    int src = 0;
    pq.push(make_pair(0,src));
    distance[src] = 0;

    while(!pq.empty()){
        int top = pq.top().second;
        pq.pop();

        if(distance[top]!= INT32_MAX){

            for (int i = 0; i < adj[top].size(); i++)
            {
                int vertex = adj[top][i].first;
                int weight = adj[top][i].second;
                if (distance[top] + weight < distance[vertex])
                {
                    distance[vertex] = distance[top] + weight;
                    pq.push(make_pair(distance[vertex],vertex));
                }
            }
        }
    }

    cout<<"shortest path is : "<<endl;
    for(int i=0;i<nodes;i++){
        cout<<distance[i]<<" ";
    }
    cout<<endl;
    return 0;
}

// using set instead of priority queue
// set also store value in ascending order so we will always get minimum distance element at th top
// in set we can erase the elements if we are getting better than at but in priority queue we cannot erase it
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>>s;
        vector<int>distance(V,1e9);
        
        s.insert({0,S});
        distance[S] = 0;
        while(!s.empty()){
            auto it = *(s.begin());
            int dis = it.first;
            int node = it.second;
            s.erase(it);
            
            for(auto i:adj[node]){
                int adjnode = i[0];
                int edgeweight = i[1];
                
                if(dis + edgeweight < distance[adjnode]){
                    // checking if distance is already modified
                    if(distance[adjnode] != 1e9)
                        s.erase({distance[adjnode],adjnode});
                    distance[adjnode] = dis + edgeweight;
                    s.insert({distance[adjnode],adjnode});
                }
            }
        }
        return distance;
    }
};

// printing shortest path using dijiskrtra
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>distance(n+1,1e9);
        vector<int>parent(n+1);
        for(int i=1;i<n+1;i++) parent[i] = i;
        pq.push({0,1});
        distance[1] = 0;
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto i:adj[node]){
                int adjnode = i.first;
                int edgeweight = i.second;
                if(dis + edgeweight < distance[adjnode]){
                    distance[adjnode] = dis + edgeweight;
                    pq.push({distance[adjnode],adjnode});
                    parent[adjnode] = node;
                }
            }
        }
        if(distance[n] == 1e9) return {-1};
        vector<int>path;
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        
        return path;
    }
};