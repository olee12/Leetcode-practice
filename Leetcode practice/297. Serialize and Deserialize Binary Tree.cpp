#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string code_str = "";
        serialize(root,code_str);
        //cout<<code_str<<endl;
       // deserialize(code_str);
        return code_str;
    }
    
    void serialize(TreeNode* root,string &str){
        if(root==NULL){
            str.push_back('X');
            str.push_back(',');
            return ;
        }
        
        int val = root->val;
        for(char &c:to_string(val)){
           str.push_back(c);
        }
        
        str.push_back(',');
        serialize(root->left,str);
        serialize(root->right,str);
        
        return ;
    }
std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
      
   }
   return tokens;
}
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        deque<string> vec;
        istringstream ss(data);
        string target;
        char deli = ',';
        while(getline(ss,target,deli)){
           // cout<<"getline : "<<target<<endl;
            vec.push_back(target);
        }
        
        return deserialize(vec);
    }
    TreeNode* deserialize(deque<string>&deq){
        string str = deq.front();
        deq.pop_front();
        if(str=="X"){
            return NULL;
        }
        //cout<<"hel "<<str<<endl;
        TreeNode *root = new TreeNode(atoi(str.c_str()));
        
        
        root->left = deserialize(deq);
        root->right = deserialize(deq);
        
        return root;
    }
};