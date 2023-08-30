#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        set<string>s(wordList.begin(),wordList.end());
        s.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord){
                return steps;
            }
            for(int i=0;i<word.size();i++){
                char orignal = word[i];
                // har ek character ko badal badal kr check krna hai
                for(char ch = 'a';ch <= 'z';ch++){
                    word[i] = ch;
                    // if word is found in the set;
                    if(s.find(word) != s.end()){
                        s.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = orignal;
            }
        }
        return 0;
    }
};