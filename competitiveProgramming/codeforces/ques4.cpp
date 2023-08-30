#include<bits/stdc++.h>
using namespace std;

bool solve(int n,int m){
    if(n%3!= 0 || m>n){
        return false;
    }
    int num1 = n/3;
    int num2 = 2*(n/3);
    if(num1 == m || num2 == m){
        return true;
    }
    return solve(num1,m) || solve(num2,m);

}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        if(m > n){
            cout<<"No"<<endl;
        }
        else if(n == m){
            cout<<"Yes"<<endl;
        }
        else{
            if(solve(n,m)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
 
    }
    return 0;
}