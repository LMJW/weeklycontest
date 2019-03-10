#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return _bst(preorder, 0, preorder.size() - 1);
    }

    TreeNode* _bst(vector<int>& order, int lo, int hi) {
        auto root = new TreeNode(order[lo]);
        bool has_right_branch = false;
        for (int i = lo + 1; i <= hi; ++i) {
            if (order[i] < order[lo]) {
                continue;
            } else {
                has_right_branch = true;
                if (lo + 1 <= i - 1) {
                    root->left = _bst(order, lo + 1, i - 1);
                }
                if (i <= hi) {
                    root->right = _bst(order, i, hi);
                }
                break;
            }
        }
        if (has_right_branch == false && lo < hi) {
            root->left = _bst(order, lo + 1, hi);
        }

        return root;
    }
};

int main() {
    Solution s;
    vector<int> a = {4, 2};
    auto x = s.bstFromPreorder(a);
}