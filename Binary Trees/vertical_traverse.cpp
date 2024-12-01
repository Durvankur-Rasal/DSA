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
   vector<vector<int>> verticalTraversal(TreeNode* root){
     vector<vector<int>> ans;
     if(root== NULL) return ans;

      // Map structure to store nodes: HD -> Level -> Sorted Node Values
     map<int , map<int,vector<int>>>nodes;
     
      // Queue for BFS traversal: Node -> {HD, Level}
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root,{0,0}});

        while(! q.empty()){
             auto temp= q.front();
             q.pop();

             TreeNode* frontNode= temp.first;
             int hd= temp.second.first;
             int lvl= temp.second.second;

             nodes[hd][lvl].push_back(frontNode->val);

             sort(nodes[hd][lvl].begin(), nodes[hd][lvl].end());

             if(frontNode->left){
                q.push({frontNode->left,{hd-1, lvl+1}});

             }

             if(frontNode->right){
                q.push({frontNode->right, {hd+1,lvl+1}});
             }
        }

        for(auto i: nodes){
            vector<int>v;
            for(auto j: i.second){
                for(auto k: j.second){
                    v.push_back(k);
                }
            }
            ans.push_back(v);
        }

        return ans;

   }


};

int main() {
    Solution solution;

    // Create the binary tree
    TreeNode* root = createTree();

    // Perform vertical traversal
    vector<vector<int>> result = solution.verticalTraversal(root);

    // Print the result
    cout << "Vertical Order Traversal:" << endl;
    for (const auto& line : result) {
        for (int val : line) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}