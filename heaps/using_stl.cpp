#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> maxheap;
    maxheap.push(4);
    maxheap.push(456);
    maxheap.push(45);
    maxheap.push(93);
    maxheap.push(2);


    priority_queue <int,vector<int>,greater<int> >minheap;

    minheap.push(4);
    minheap.push(456);
    minheap.push(45);
    minheap.push(93);
    minheap.push(2);

cout<<minheap.top()<<endl;

    return 0;
}