#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        unordered_map<int,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        if(mp.size() == 1) cout<<-1<<endl;
        else{
            bool flag = false;
            for(auto it:mp){
                if(it.second == 3) flag = true;
            }
            if(flag == true) cout<<6<<endl;
            else cout<<4<<endl;        
        }
    }
    return 0;
}