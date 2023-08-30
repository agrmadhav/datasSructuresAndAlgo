#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s[n];
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        int count = 1;
        for(int i=1;i<n;i++){
            if(s[i] == s[0]) count++;
        }
        cout<<count<<endl;
    }
}