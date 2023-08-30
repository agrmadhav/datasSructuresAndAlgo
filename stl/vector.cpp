#include<bits/stdc++.h>
using namespace std;

int main()
{
    // int basic[3] = {1,2,3};

    // // stl array same as simple array
    // array<int,4> a = {1,2,3,4};
    // for(int i =0;i<a.size();i++){
    //     cout<<a[i]<<endl;
    // }
    // cout<<"element at second index -> "<<a.at(2)<<endl;
    // cout<<"first element -> "<<a.front()<<endl;
    // cout<<"second element -> "<<a.back()<<endl;


    // vectors - dynamic array
    vector<int> v;
    cout<<"size->"<<v.size()<<" capacity->"<<v.capacity()<<endl;
    v.push_back(1);
    cout<<"size->"<<v.size()<<" capacity->"<<v.capacity()<<endl;
    v.push_back(2);
    cout<<"size->"<<v.size()<<" capacity->"<<v.capacity()<<endl;
    v.push_back(3);
    cout<<"size->"<<v.size()<<" capacity->"<<v.capacity()<<endl;;
    v.push_back(4);
    cout<<"size->"<<v.size()<<" capacity->"<<v.capacity()<<endl;


    cout<<"element at second index -> "<<v.at(2)<<endl;
    cout<<"first element -> "<<v.front()<<endl;
    cout<<"second element -> "<<v.back()<<endl;

    cout<<"before pop"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    v.pop_back();
    
    cout<<"after pop"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> a(5,1);
     // 5 denotes size and 1 denotes initialise to 1

    cout<<"print a"<<endl;
    for(int i:a){
        cout<<i<<" ";
    }
    return 0;
}