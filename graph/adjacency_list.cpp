#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj[],int u,int v){
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void printgraph(vector<int> adj[],int vertex){
    for(int i=0;i<vertex;i++){
        for(int x: adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

int main(){

    int v = 4;
    vector<int> adj[v];

    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,1,3);

    printgraph(adj,v);

    return 0;
}


// using maps
