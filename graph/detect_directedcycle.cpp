#include<bits/stdc++.h>
using namespace std;

bool detectcycle_bfs(int nodes, vector<int>adj[]){
    int count = 0;
    vector<int>in_degree(nodes,0);

    for(int i=0;i<nodes;i++){
        for(int j=0;j<adj[i].size();j++){
                in_degree[adj[i][j]]++;
        }
    }

    queue<int>q;
    for(int i=0;i<nodes;i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int p = q.front();
        q.pop();

        count++;

        for(int i=0;i<adj[p].size();i++){
                in_degree[adj[p][i]]--;
                // now checking indegree again
                if(in_degree[adj[p][i]] == 0){
                    q.push(adj[p][i]);
                }
        }
    }
    if(count!=nodes){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    int nodes, edges;
    cin>>nodes>>edges;

    vector<int>adj[nodes];
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    if(detectcycle_bfs(nodes,adj)){
        cout<<"there exist a cycle in graph"<<endl;
    }
    else{
        cout<<"directed acyclic graph"<<endl;
    }
    return 0;
}