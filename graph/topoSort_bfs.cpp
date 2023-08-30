// kahn algorithm
#include<bits/stdc++.h>
using namespace std;

vector<int> topological_sort(int nodes, vector<int>adj[]){
    vector<int>topo;
    vector<int>in_degree(nodes,0);

    // initially calculating indegree of each node
    for(int i=0;i<nodes;i++){
        for(auto j : adj[i]){
            in_degree[j]++;
        }
    }

    queue<int>q;
    for(int i=0;i<nodes;i++){
        // pushing node of indegree 0 in the queue
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int p = q.front();
        q.pop();
        topo.push_back(p);

        // decreasing indegree of the node connected to p
        for(int i=0;i<adj[p].size();i++){
                in_degree[adj[p][i]]--;
                // now checking indegree again
                if(in_degree[adj[p][i]] == 0){
                    q.push(adj[p][i]);
                }
        }
    }
    return topo;
}

int main()
{
    int nodes, edges;
    cin>>nodes>>edges;

    vector<int>adj[nodes];
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
    }

    vector<int>res = topological_sort(nodes,adj);
    for(int i=0;i<nodes;i++){
        cout<<res[i]+1<<" ";
    }
    return 0;
}

// for lexicographically small topological sort use priority queue instead of using simple queue
// kahn algorithm
// #include<bits/stdc++.h>
// using namespace std;

// vector<int> topological_sort(int nodes, vector<int>adj[]){
//     vector<int>topo;
//     vector<int>in_degree(nodes,0);

//     // initially calculating indegree of each node
//     for(int i=0;i<nodes;i++){
//         for(auto j : adj[i]){
//             in_degree[j]++;
//         }
//     }

//     priority_queue<int,vector<int>,greater<int>> pq;
//     for(int i=0;i<nodes;i++){
//         // pushing node of indegree 0 in the queue
//         if(in_degree[i] == 0){
//             pq.push(i);
//         }
//     }

//     while(!pq.empty()){
//         int p = pq.top();
//         pq.pop();
//         topo.push_back(p);

//         // decreasing indegree of the node connected to p
//         for(int i=0;i<adj[p].size();i++){
//                 in_degree[adj[p][i]]--;
//                 // now checking indegree again
//                 if(in_degree[adj[p][i]] == 0){
//                     pq.push(adj[p][i]);
//                 }
//         }
//     }
//     return topo;
// }

// int main()
// {
//     int nodes, edges;
//     cin>>nodes>>edges;

//     vector<int>adj[nodes];
//     for(int i=0;i<edges;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u-1].push_back(v-1);
//     }

//     vector<int>res = topological_sort(nodes,adj);
//     for(int i=0;i<nodes;i++){
//         cout<<res[i]+1<<" ";
//     }
//     return 0;
// }