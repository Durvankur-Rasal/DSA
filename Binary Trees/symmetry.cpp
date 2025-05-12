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

    bool solve(TreeNode* root1 ,TreeNode* root2){
        if(root1==NULL || root2==NULL){
            return root1==root2;
        }

        return root1->val==root2->val &&
              solve(root1->left,root2->right)&&
              solve(root1->right,root2->left);
         
    }

    bool symmetry(TreeNode* root){
        if(root==NULL) return true;

        return solve(root->left,root->right);
    }

  
   
    
   
};

int main() {
    Solution solution;

    // Create the binary tree
    TreeNode* root = createTree();

    // Perform vertical traversal
    // vector<int> result = solution.leftView(root);
  bool result = solution.symmetry(root);

    // Print the result
   if(result){
    cout<<"It is symmetrical "<<endl;
   }

   else{
    cout<<"It is not symmetrical";
   }

    return 0;
}