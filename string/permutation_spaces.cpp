#include<bits/stdc++.h>
using namespace std;

void solve(string input,string output){
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    string output1 = output;
    string output2 = output;
    output1.push_back(' ');
    output1.push_back(input[0]);
    output2.push_back(input[0]);
    input.erase(input.begin() + 0);

    solve(input,output1);
    solve(input,output2);
    return;
}

int main(){
    string input;
    cin>> input;
    string output = "";
    output.push_back(input[0]);
    input.erase(input.begin() + 0);

    solve(input,output);
    return 0;
}