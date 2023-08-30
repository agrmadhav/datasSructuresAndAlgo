#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> ans;
       stack<pair<int,int>> s;
       for(int i=0;i<n;i++){
           if(s.empty()){
               ans.push_back(-1);
           }
           else if(!s.empty() && s.top().first > price[i]){
               ans.push_back(s.top().second);
           }
           else if(!s.empty() && s.top().first <= price[i]){
               while(!s.empty() && s.top().first <= price[i]){
                   s.pop();
               }
               if(s.empty()){
                   ans.push_back(-1);
               }
               else{
                   ans.push_back(s.top().second);
               }
           }
           s.push({price[i],i});
       }
       for(int i=0;i<ans.size();i++){
           ans[i] = i-ans[i];
       }
       return ans;
    }
};
