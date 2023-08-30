#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<string> q;
    q.push("love");
    q.push("babbar");
    q.push("gabbar");

    cout<< q.front()<<endl;
    q.pop();
    cout<< q.front()<<endl;

    // priority queue
    priority_queue<int>maxh; // max heap

    maxh.push(1);
    maxh.push(3);
    maxh.push(2);
    maxh.push(0);
    int n = maxh.size();
    for(int i =0;i<n;i++){

        cout<<maxh.top()<<" ";
        maxh.pop();
    }
    cout<<endl;

    priority_queue<int , vector<int>, greater<int> >minh;

    return 0;
}