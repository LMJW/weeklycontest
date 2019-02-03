#include <iostream>
#include <string>
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
    string smallestFromLeaf(TreeNode* root) {
        for (int i = 0; i < 1000; ++i) {
            spath.push_back(25);
        }
    }
    vector<int> spath;

    void dfs(TreeNode* root, vector<int> path) {
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            auto l = std::min(spath.size(), path.size());
            for (int i = l - 1; i > -1; --i) {
                if
                    path[i]
            }
        }
    }
};

int main() {}