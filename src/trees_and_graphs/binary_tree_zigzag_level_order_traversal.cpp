#include <vector>
#include <queue>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);

        bool reverse = false;
        int next_level_count = 1;
        while (!q.empty()) {
            const int cur_level_count = next_level_count;
            next_level_count = 0;
            vector<int> cur_res(cur_level_count);

            for (int i = 0; i < cur_level_count; i++) {
                TreeNode* cur = q.front();
                q.pop();

                int index = reverse ? cur_level_count - 1 - i : i;
                cur_res[index] = cur->val;

                if (cur->left != nullptr) {
                    q.push(cur->left);
                    next_level_count++;
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                    next_level_count++;
                }
            }
            res.push_back(move(cur_res));
            reverse ^= true;
        }

        return res;
    }
};