#include<bits/stdc++.h>
using namespace std;

int getlength(char name[]){
    int length = 0;
    for(int i=0;name[i] != '\0';i++){
        length++;
    }
    return length;
}

bool isPalindrome(char name[],int n){
    int i=0;
    int j = n-1;
    while(i<=j){
        if(name[i] != name[j]){
            return false;
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}

int main(){

    char name[20];
    cin>>name;

    cout<<isPalindrome(name,getlength(name))<<endl;
    return 0;
}


void reverse_words(char* s) {
  // Reverse the entire string
  int start = 0, end = strlen(s) - 1;
  while (start < end) {
    swap(s[start], s[end]);
    start++;
    end--;
  }

  // Reverse each word in the string
  start = 0;
  for (int current = 0; current < strlen(s); current++) {
    if (s[current] == ' ') {
      continue;
    }
    start = current;
    while (s[current] != ' ' && current < strlen(s)) {
      current++;
    }
    end = current - 1;
    while (start < end) {
      swap(s[start], s[end]);
      start++;
      end--;
    }
  }
}

