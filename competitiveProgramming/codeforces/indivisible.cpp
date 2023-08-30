#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n == 1) cout<<1<<endl;
        else if(n%2 == 1) cout<<-1<<endl;
        else if(n == 2) cout<<1<<" "<<2<<endl;
        else{
            cout<<2<<" "<<1<<" ";
            for(int i=3;i<=n;i++){
                if(i%2 == 1) cout<<i+1<<" ";
                else cout<<i-1<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}