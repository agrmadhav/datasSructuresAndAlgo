// #include<bits/stdc++.h>
// using namespace std;

// // void bfs(vector<int> adj[],int v,int s){
// //     bool vis[v+1];
// //     for(int i = 0;i<v;i++){
// //         vis[i] = false;
// //     }
// //     queue<int>q;
// //     q.push(s);
// //     vis[s] = true;

// //     while(!q.empty()){
// //         int p = q.front();
// //         cout<<p<<" ";
// //         q.pop();

// //         for(int i =0;i < adj[p].size();i++){
// //             if((vis[adj[p][i]]) == false){
// //                 q.push(adj[p][i]);
// //                 vis[adj[p][i]] = true;
// //             }
// //         }
// //     }
// // }

// void bfs(vector<int> adj[],int s,bool vis[]){
//     queue<int>q;
//     vis[s] = true;
//     q.push(s);

//     while(!q.empty()){
//         int p = q.front();
//         q.pop();
//         // cout<<p<<" ";

//         for(int i =0;i < adj[p].size();i++){
//             if((vis[adj[p][i]]) == false){
//                 q.push(adj[p][i]);
//                 vis[adj[p][i]] = true;
//             }
//         }
//     }
// }

// void bfsdisconnected(vector<int>adj[],int v){
//     bool vis[v+1];
//     for(int i=0;i<v;i++){
//         vis[i] = false;
//     }
//     for(int i=0;i<v;i++){
//         if(vis[i] == false){
//             bfs(adj,i,vis);
//         }
//     }
// }

// int connected_componenets(vector<int>adj[],int v){
//     bool vis[v+1];
//     for(int i=0;i<v;i++){
//         vis[i] = false;
//     }
//     int count = 0;
//     for(int i=0;i<v;i++){
//         if(vis[i] == false){
//             bfs(adj,i,vis);
//             count++;
//         }
//     }
//     return count;
// }

// void addedge(vector<int> adj[],int u,int v){
//     adj[v].push_back(u);
//     adj[u].push_back(v);
// }

// void printgraph(vector<int> adj[],int vertex){
//     for(int i=0;i<vertex;i++){
//         for(int x: adj[i]){
//             cout<<x<<" ";
//         }
//         cout<<endl;
//     }
// }

// int main(){

//     int v = 7;
//     vector<int> adj[v];

//     addedge(adj,0,1);
//     addedge(adj,0,2);
//     addedge(adj,1,3);
//     addedge(adj,2,3);
//     addedge(adj,4,5);
//     addedge(adj,5,6);
//     addedge(adj,4,6);

//     // cout<<"bfs traversal of the disconnected graph is : ";
//     // bfsdisconnected(adj,v);
//     // cout<<endl;
//     cout<<"number of connected components are : "<<connected_componenets(adj,v)<<endl;
//     // printgraph(adj,v);

//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], vector<bool>&vis, int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        cout << p << " ";
        for (int i = 0; i < adj[p].size(); i++)
        {
            if (vis[adj[p][i]] == false)
            {
                q.push(adj[p][i]);
                vis[adj[p][i]] = true;
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    int u, v;
    vector<int> adj[nodes + 1];

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(nodes+1,false);

    for (int i = 0; i < nodes; i++)
    {
        if(vis[i] == false){
            bfs(adj,vis,i);
        }
    }

    return 0;
}