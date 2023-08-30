#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<int>v(n+1);
    for(int i=1;i<n+1;i++){
        cin>>v[i];
    }
    
    vector<int>dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    vector<int>freq(n+1);
    freq[1] = 1;

    if(n>=2){
        if(v[1] >= v[2]){
            freq[2] = 2;
        }
        else freq[2] = 1;
    }

    for(int i=3;i<n+1;i++){
        if(v[i]>v[i-1]){
            dp[i] = dp[i-1] + 1;
            freq[i] = 1;
        }
        else{
            if(freq[i-1] == 1){
                dp[i] = dp[i-1] + 1;
            }
            else dp[i] = dp[i-1];
            freq[i] = 2;
        }
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        if(r-l+1<=2){
            cout<<r-l+1<<endl;
        }
        else{
            int ans = dp[r] - dp[l-1];
            if(dp[l+1] == dp[l-1]) ans += 2;
            else if(dp[l]==dp[l-1]||dp[l]==dp[l+1]) ans++;
            cout<<ans<<endl;
        }
    }

    return 0;
}