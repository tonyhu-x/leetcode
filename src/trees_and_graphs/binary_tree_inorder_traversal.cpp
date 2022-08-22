#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        // the idea is that for any node in s,
        // their left child has already been visited
        stack<TreeNode*> s;
        auto* cur = root;

        while (!s.empty() || cur) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            }
            else {
                cur = s.top();
                s.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }

    vector<int> inorderTraversalRecursive(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        if (root->left != nullptr) {
            res = inorderTraversalRecursive(root->left);
        }
        res.push_back(root->val);
        if (root->right != nullptr) {
            auto tmp = inorderTraversalRecursive(root->right);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }

        return res;
    }
};