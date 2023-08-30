#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        char c = s[0];
        // cout << c <<endl;
        string ans;
        // ans.push_back(c);
        for(int i=1;i<n;i++){
            if(s[i] == c){
                ans = ans + c;
                c = s[i+1];
                i++;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}