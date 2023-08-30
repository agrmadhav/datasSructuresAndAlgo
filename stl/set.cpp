#include<bits/stdc++.h>
using namespace std;

// stores unique element
// implement using bst
// return in sorted order

// in unorder set element come in random way

int main(){
    set<int> s;
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(7);

    // insert ki complexity O(logn)
    for(auto i:s){
        cout<<i<<endl;
    }
    cout<<endl;
    // s.erase(s.begin());
    set<int>::iterator it = s.begin();
    it++;
    it++;

    s.erase(it);

    for(auto i:s){
        cout<<i<<endl;
    }

    cout<<endl;
    cout<<s.count(5)<<endl;

}