#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>& ans,int delRow[],int delCol[],int iniColor,int color){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        // there are exactly four neighbours
        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
            image[nrow][ncol] == iniColor && ans[nrow][ncol] != color){
                dfs(nrow,ncol,image,ans,delRow,delCol,iniColor,color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;

        // creating deltarow and deltacolumn for neightbouring row and column
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(sr,sc,image,ans,delRow,delCol,iniColor,color);

        return ans;        
    }
};

