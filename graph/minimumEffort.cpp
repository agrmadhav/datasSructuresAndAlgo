#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>distance(n,vector<int>(m,1e9));
        // {diff,{row,col}} in priority queue
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        distance[0][0] = 0;
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!pq.empty()){
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            // checking for destination while popping out from priority queue and not while inserting
            if(row == n-1 && col == m-1){
                return diff;
            }
            
            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]),diff);
                    if(newEffort < distance[nrow][ncol]){
                        distance[nrow][ncol] = newEffort;
                        pq.push({distance[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};