#include <iostream>
#include <map>
#include <sort>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct pos {
    int val;
    int y;
    pos() : val(0), y(0) {}
    pos(int v, int y) : val(v), y(y) {}
    friend bool operator<(const pos& p1, const pos& p2) {
        if (p1.y == p2.y) {
            return p1.val < p2.val;
        }
        return p1.y < p2.y;
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pos>> hash;
        _dfs_(root, 0, 0, hash);

        vector<vector<int>> res;

        for (auto e : hash) {
            auto t = e.second;
            stable_sort(t.begin(), t.end());
            vector<int> tmp;
            for (auto ee : t) {
                tmp.push_back(ee.val);
            }
            res.push_back(tmp);
        }
        return res;
    }

    void _dfs_(TreeNode* root, int x, int y, map<int, vector<pos>>& hash) {
        auto it = hash.find(x);
        if (it == hash.end()) {
            auto t = vector<pos>{pos(root->val, y)};
            hash[x] = t;
        } else {
            hash[x].push_back(pos(root->val, y));
        }
        if (root->left != NULL) {
            _dfs_(root->left, x - 1, y + 1, hash);
        }
        if (root->right != NULL) {
            _dfs_(root->right, x + 1, y + 1, hash);
        }
    }
};