#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int row,int col,vector<vector<int>>&visited,
    int &cnt,vector<vector<int>>&grid){
        visited[row][col] = 1;
        cnt++;
        int m = grid.size();
        int n = grid[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n &&
            !visited[nrow][ncol] &&grid[nrow][ncol] == 1){
                dfs(nrow,ncol,visited,cnt,grid);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));

        int maxi = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int cnt = 0;
                    dfs(i,j,visited,cnt,grid);
                    maxi = max(maxi,cnt);
                }
            }
        }
        return maxi;
    }
};