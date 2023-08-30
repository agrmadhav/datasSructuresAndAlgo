#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
        pair<int, int> destination) {
        // no need of using priority queue as distance is increasing equally in each level
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>distance(n,vector<int>(m,1e9));
        distance[source.first][source.second] = 0;
        q.push({0,{source.first,source.second}});
        // checking edge case
        if(source.first == destination.first && source.second == destination.second){
            return 0;
        }

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                grid[nrow][ncol] == 1 && dis+1<distance[nrow][ncol]){
                    distance[nrow][ncol] = dis + 1;
                    if(nrow == destination.first && ncol == destination.second){
                        return distance[nrow][ncol];
                    }
                    q.push({distance[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};