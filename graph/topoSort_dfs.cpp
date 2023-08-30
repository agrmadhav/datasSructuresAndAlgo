#include<bits/stdc++.h>
using namespace std;

void toposort(int node,vector<bool>&visited,stack<int>&s,vector<int>adj[]){
    visited[node] = true;

    for(auto i: adj[node]){
        if(!visited[i]){
            toposort(i,visited,s,adj);
        }
    }
    s.push(node);
}

int main(){
    int nodes,edges;
    cin>>nodes>>edges;

    vector<int>adj[nodes+1];

    int u,v;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<bool>visited(nodes+1,false);
    stack<int>s;

    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            toposort(i,visited,s,adj);
        }
    }

    vector<int>ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    cout<<"topological sort of the given graph is : "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}