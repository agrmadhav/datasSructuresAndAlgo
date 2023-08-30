#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    void solve(string output,int open,int close,vector<string>& ans){
        if(open == 0 && close == 0){
            ans.push_back(output);
            return;
        }
        if(open != 0){
            string output1 = output;
            output1.push_back('(');
            solve(output1,open-1,close,ans);
        }
        if(close>open){
            string output2 = output;
            output2.push_back(')');
            solve(output2,open,close-1,ans);
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = n;
        int close = n;
        string output = "";

        solve(output,open,close,ans);
        return ans;
    }
};