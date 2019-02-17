#include <iostream>
#include <vector>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        auto p1 = _bfs(root, nullptr, 0, x);
        auto p2 = _bfs(root, nullptr, 0, y);

        if (p1.first == p2.first && p1.second != p2.second) {
            return true;
        }
        return false;
    }
    // pair <depth, parent>
    pair<int, int> _bfs(TreeNode* cur, TreeNode* p, int depth, int t) {
        ++depth;
        auto res = make_pair(depth, -1);
        if (cur->val == t) {
            if (p != nullptr) {
                res.second = p->val;
            }
            return res;
        } else {
            if (cur->left != nullptr) {
                res = _bfs(cur->left, cur, depth, t);
                if (res.second != -1) {
                    return res;
                }
            }
            if (cur->right != nullptr) {
                res = _bfs(cur->right, cur, depth, t);
                if (res.second != -1) {
                    return res;
                }
            }
        }
        return res;
    }
};

int main() {}