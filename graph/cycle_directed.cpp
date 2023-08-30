#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int>adj[],vector<bool>&visited,
    vector<bool>&pathvisited,int s){
    visited[s] = true;
    pathvisited[s] = true;
    for(int i=0;i<adj[s].size();i++){
        if((visited[adj[s][i]] == false) && (dfs(adj,visited,pathvisited,adj[s][i]) == true)){
            return true;
        }
        else if(pathvisited[adj[s][i]] == true){
            return true;
        }
    }
    pathvisited[s] = false;
    return false;
}

bool iscycle(vector<int>adj[],vector<bool>&visited,vector<bool>&recursive_stack,int nodes){

    for(int i=0;i<nodes;i++){
        if(visited[i] == false){
            if(dfs(adj,visited,recursive_stack,i) == true){
                return true;
            }
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
    }
    vector<bool>visited(nodes+1,false);
    vector<bool>pathvisited(nodes+1,false);

    if(iscycle(adj,visited,pathvisited,nodes) == true){
        cout<<"there is cycle"<<endl;
    }
    else{
        cout<<"no cycle found"<<endl;
    }
    return 0;
}