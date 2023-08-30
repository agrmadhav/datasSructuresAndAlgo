#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 1;
        int high = 1e9;
        while(low <= high){
            int mid = low + (high - low)/2;
            int cnt = 0;
            for(int i=0;i<n;i++){
                cnt += (upper_bound(matrix[i].begin(),matrix[i].end(),mid) - 
                                                       matrix[i].begin());
            }
            if(cnt <= (n*m)/2) low = mid + 1;
            else high = mid-1;
        }
        return low;
    }
};