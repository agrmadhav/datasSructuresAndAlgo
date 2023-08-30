#include<bits/stdc++.h>
using namespace std;

int main(){
    int v,e;
    cin>>v>>e;

    int adjmatrix[v+1][v+1];
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;

        adjmatrix[v1][v2] = 1;
        adjmatrix[v2][v1] = 1;
    }

    return 0;
}