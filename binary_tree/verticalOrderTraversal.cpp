#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;

        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int vertical = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            nodes[vertical][level].insert(node->data);

            if(node->left != NULL){
                q.push({node->left,{vertical-1,level+1}});
            }
            if(node->right != NULL){
                q.push({node->right,{vertical+1,level+1}});
            }
        }
        for(auto i:nodes){
            vector<int> v;
            for(auto j: i.second ){
                v.insert(v.end(),j.second.begin(),j.second.end());
            }
            result.push_back(v);
        }
        return result;
    }
};