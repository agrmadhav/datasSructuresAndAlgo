#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        long long mod = 1e9 + 7;;
        vector<long long>distance(n,1e15);
        vector<long long>ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        //{distance,node}
        pq.push({0,0});
        distance[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto i:adj[node]){
                int adjnode = i.first;
                int edgeweight = i.second;
                // agar pehli baar kam distance mile toh
                if(dis + edgeweight < distance[adjnode]){
                    distance[adjnode] = dis + edgeweight;
                    ways[adjnode] = ways[node];
                    pq.push({distance[adjnode],adjnode});
                }
                // ek aur baar same hi short distance mili ho agar
                else if(dis + edgeweight == distance[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};