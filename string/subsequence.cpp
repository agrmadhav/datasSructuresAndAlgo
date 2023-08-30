#include<bits/stdc++.h>
using namespace std;

void solve(string input,string output){
    if(input.empty()){
        cout<<output<<" ";
        return;
    }
    string op1 = output;
    string op2 = output;
    op2.push_back(input[0]); // making choices of input by our decisions
    input.erase(input.begin() + 0);

    solve(input,op2);
    solve(input,op1);
    return;
}

int main(){
    string input;
    cin>>input;
    string output = "";
    solve(input,output);
    return 0;
}