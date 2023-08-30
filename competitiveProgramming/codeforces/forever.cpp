#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        map<int, int> mp;
        while (m--){
            int a, b;
            cin >> a >> b;
            mp[a]++;
            mp[b]++;
        }
        int x = -1, y = -1;
        int maxi = 0, mini = INT_MAX;
        for (auto i : mp){
            if (i.second != 1){
                mini = min(mini, i.second);
                maxi = max(maxi, i.second);
            }
        }
        if (maxi == mini){
            x = maxi;
            y = maxi - 1;
        }
        else{
            int c = 0, cnt = 0;
            for (auto i : mp){
                if (i.second == mini)
                    c++;
                else if (i.second == maxi)
                    cnt++;
            }
            if (c > cnt){
                x = maxi, y = mini - 1;
            }
            else{
                x = mini, y = maxi - 1;
            }
        }
        cout << x << " " << y << endl;
    }
    return 0;
}
