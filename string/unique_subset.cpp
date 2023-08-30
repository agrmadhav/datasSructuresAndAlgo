#include<bits/stdc++.h>
using namespace std;
class solution
{
    private:
    void solve(vector<int> arr, vector<int> output,set<vector<int>>&ans){
        if(arr.empty()){
            ans.insert(output);
            return;
        }
        vector<int> op1 = output;
        vector<int> op2 = output;
        op2.push_back(arr[0]);
        arr.erase(arr.begin() + 0);
        
        solve(arr,op1,ans);
        solve(arr,op2,ans);
        return;
    }
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        sort(arr.begin(),arr.end());
        set<vector<int>> ans;
        vector<int> output;
        solve(arr,output,ans);
        
        vector<vector<int>>result;
        
        for(auto i: ans){
            result.push_back(i);
        }
        return result;
    }
};