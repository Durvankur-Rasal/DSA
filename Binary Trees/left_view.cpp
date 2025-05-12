#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* createTree() {
    // Example tree:
    //       1
    //      / \
    //     2   3
    //    / \ / \
    //   4  5 6  7
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

class Solution{
    public:

    void leftRecursive(TreeNode* root, int level,vector<int>&ans){
        if(root==NULL) return ;

        if(ans.size()==level){
            ans.push_back(root->val);
        }

        leftRecursive(root->left,level+1,ans);

        leftRecursive(root->right,level+1,ans);


    }

    void rightRecursive(TreeNode* root, int level,vector<int>&ans){
            if(root==NULL) return ;

        if(ans.size()==level){
            ans.push_back(root->val);
        }

        leftRecursive(root->right,level+1,ans);

        leftRecursive(root->left,level+1,ans);

    }

    vector<int>rightView(TreeNode* root){
      vector<int>ans;
      rightRecursive(root,0,ans);
      return ans;
    

      }

   vector<int>leftView(TreeNode* root){
      vector<int>ans;
      leftRecursive(root,0,ans);
      return ans;
    

      }
   
    
   
};

int main() {
    Solution solution;

    // Create the binary tree
    TreeNode* root = createTree();

    // Perform vertical traversal
    // vector<int> result = solution.leftView(root);
    vector<int> result = solution.rightView(root);

    // Print the result
    cout << "left view:" << endl;
    for (const auto& val : result) {
       
            cout << val << " ";
    }

    return 0;
}