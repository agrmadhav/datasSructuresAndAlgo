#include<bits/stdc++.h>
using namespace std;

int main(){

    stack<string> s;
    s.push("hi");
    s.push("hello");
    s.push("hey");

    cout<<" stack top element : "<<s.top()<<endl;
    s.pop();
    cout<<" stack top element : "<<s.top()<<endl;
}
