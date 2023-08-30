#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long > ans;
        stack<long long > s;
        for(int i=arr.size()-1;i>=0;i--){
            if(s.empty()){
                ans.push_back(-1);
            }
            else if(!s.empty() && s.top() > arr[i]){
                ans.push_back(s.top());
            }
            else if(!s.empty() && s.top() <= arr[i]){
                while(!s.empty() && s.top() <= arr[i]){
                    s.pop();
                }
                // while loop terminate due to empty of stack
                if(s.empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(s.top());
                }
            }
            s.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};