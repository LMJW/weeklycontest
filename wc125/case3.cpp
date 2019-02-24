#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (val > root->val) {
            TreeNode* p = new TreeNode(val);
            p->left = root;
            return p;
        }
        _insert(nullptr, root, val);

        return root;
    }

    void _insert(TreeNode* parent, TreeNode* cur, int val) {
        if (cur != nullptr) {
            if (val > cur->val) {
                // parent will exist && parent will larger than val
                // TreeNode newcur(val);
                TreeNode* newcur = new TreeNode(val);
                newcur->left = cur;
                if (parent->left != nullptr && parent->left->val == cur->val) {
                    parent->left = newcur;
                }
                if (parent->right != nullptr &&
                    parent->right->val == cur->val) {
                    parent->right = newcur;
                }
            } else {
                _insert(cur, cur->right, val);
            }
        } else {
            // TreeNode newcur(val);
            TreeNode* newcur = new TreeNode(val);

            parent->right = newcur;
        }
    }
};

int main() {}