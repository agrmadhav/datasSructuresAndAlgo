#include<bits/stdc++.h>
using namespace std;

// using bfs
class Solution {
    private:
    void bfs(int row,int col,vector<vector<int>> &visited, vector<vector<char>>& grid){
        visited[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
        // visiting all the neighbours in eight direction
            for(int delrow =-1;delrow<=1;delrow++){
                for(int delcol = -1;delcol<=1;delcol++){
                    int nrow = row+delrow;
                    int ncol = col+delcol;
                    if(nrow >= 0 && nrow < n && ncol>=0 && ncol<m &&
                    !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                        visited[nrow][ncol] = 1;
                        bfs(nrow,ncol,visited,grid);
                    }
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        int islands = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    bfs(i,j,visited,grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};

// time complexity : O(n*m*8)

// using dfs
class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>&visited,vector<vector<char>>& grid,
    int delrow[],int delcol[]){
        visited[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<4;i++){
            int nrow = row+ delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
            !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                dfs(nrow,ncol,visited,grid,delrow,delcol);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        vector<vector<int>> visited(n,vector<int>(m,0));
        int islands = 0;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(i,j,visited,grid,delrow,delcol);
                    islands++;
                }
            }
        }
        return islands;
    }
};