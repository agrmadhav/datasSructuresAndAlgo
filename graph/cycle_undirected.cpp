#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int>adj[],vector<bool>&visited,int s,int parent){
    visited[s] = true;

    for(int i=0;i<adj[s].size();i++){
        if(visited[adj[s][i]] == false){
            if(dfs(adj,visited,adj[s][i],s) == true){
                return true;
            }
        }
        else if(adj[s][i]!= parent){
            return true;
        }
    }
    return false;
}

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    int u,v;
    vector<int>adj[nodes+1];
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>visited(nodes+1,false);

    for(int i=0;i<nodes;i++){
        if(visited[i] == false){
            if(dfs(adj,visited,i,-1) == true){
                cout<<"there is cycle in graph"<<endl;
            }
        }
        cout<<"no cycle"<<endl;
    }
    return 0;
}

