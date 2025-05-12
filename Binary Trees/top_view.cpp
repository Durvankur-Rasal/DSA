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

    vector<int> topView(TreeNode* root){
        vector<int>ans;
        if(root ==NULL) return ans;

        map<int,int>mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});

        while(! q.empty()){
            auto temp= q.front();
            q.pop();

            TreeNode* p=temp.first;
            int line= temp.second;

            if( mp.find(line) == mp.end()){
                mp[line]=p->val;
            }
          

            if(p->left){
                q.push({p->left, line-1});
            }

            if(p->right){
                q.push({p->right, line+1});
            }
        }

        for(auto it:mp){
            ans.push_back(it.second);
        }

        return ans;

    }
   
};

int main() {
    Solution solution;

    // Create the binary tree
    TreeNode* root = createTree();

    // Perform vertical traversal
    vector<int> result = solution.topView(root);

    // Print the result
    cout << "Top view:" << endl;
    for (const auto& val : result) {
       
            cout << val << " ";
    }

    return 0;
}