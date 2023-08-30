#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> d;

    d.push_back(1);
    d.push_front(2);
    d.push_front(5);
    d.push_back(3);
    d.push_back(4);

    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;
    d.pop_front();
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"print first index element-> "<<d.at(1)<<endl;

    cout<<"before erase size is "<<d.size()<<endl;
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;
    d.erase(d.begin(),d.begin()+2);
    cout<<"after erase size is "<<d.size()<<endl;
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int t; cin >> t;
// 	while (t--) {
// 	    int n; cin >> n;
// 	    deque<int> dq;
// 	    for (int i = 0; i < n; ++i) {
// 	        int x; cin >> x;
// 	        dq.push_back(x);
// 	    }
// 	    int ans = 0;
// 	    while (dq.size() > 1) {
// 	        int x = dq.front(), y = dq.back();
// 	        dq.pop_front(); dq.pop_back();
// 	        if (x == y) continue;
// 	        ++ans;
// 	        if (x < y) dq.push_back(y-x);
// 	        else dq.push_front(x-y);
// 	    }
// 	    cout << ans << '\n';
// 	}
// 	return 0;
    return 0;
}