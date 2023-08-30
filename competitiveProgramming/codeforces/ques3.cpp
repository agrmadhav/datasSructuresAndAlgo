#include<bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    cin>>n;
 
    int arr1[n],arr2[n],arr3[n],arr4[n];
    int a=0,b=0,c=0,d=0;
 
    for(int i=0;i<n;i++){
    int x;
    cin>>x;
 
    char s[3];
    cin>>s;
 
    if(s[0]=='0' && s[1]=='0'){
        arr1[a++]=x;
    }
 
    else if(s[0]=='0' && s[1]=='1'){
        arr2[b++]=x;
    }
 
    else if(s[0]=='1' && s[1]=='0'){
        arr3[c++]=x;
    }
 
    else{
        arr4[d++]=x;
    }
    }
 
    int m=INT_MAX,f=0;
    if(d!=0){
        int x=INT_MAX;
        for(int i=0;i<d;i++){
            if(arr4[i]<x){
                x=arr4[i];
            }
        }
        f=1;
        m=x;
    }
 
    if(b!=0&&c!=0){
        int x=INT_MAX,y=INT_MAX;
        for(int i=0;i<c;i++){
            if(arr3[i]<x){
                x=arr3[i];
            }
        }
        for (int i=0;i<b;i++){
            if(arr2[i]<y){
                y=arr2[i];
            }
        }
        if(x+ y<m)
            m=x+y;
        f=1;
    }
 
    if(f==1){
        cout<<m<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
 
    return;
}
 
int main()
{
    int t;
    cin >> t;
 
    while(t--){
        solve();
    }
 
    return 0;
}