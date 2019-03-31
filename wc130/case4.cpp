#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        set<pair<int, int>> reachable;
        int count_total = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[i].size(); ++j) {
                if (A[i][j] == 1) {
                    ++count_total;
                } else {
                    continue;
                }
                if (i == 0 || i == A.size() - 1 || j == 0 ||
                    j == A[i].size() - 1) {
                    if (reachable.find(make_pair(i, j)) == reachable.end()) {
                        dfs(i, j, A, reachable);
                    }
                }
            }
        }
        return count_total - reachable.size();
    }

    void dfs(int i, int j, vector<vector<int>>& A, set<pair<int, int>>& r) {
        r.insert(make_pair(i, j));
        int n = A.size();
        int m = A[i].size();
        if (i - 1 > -1 && A[i - 1][j] == 1 &&
            r.find(make_pair(i - 1, j)) == r.end()) {
            dfs(i - 1, j, A, r);
        }
        if (i + 1 < n && A[i + 1][j] == 1 &&
            r.find(make_pair(i + 1, j)) == r.end()) {
            dfs(i + 1, j, A, r);
        }
        if (j + 1 < m && A[i][j + 1] == 1 &&
            r.find(make_pair(i, j + 1)) == r.end()) {
            dfs(i, j + 1, A, r);
        }
        if (j - 1 > -1 && A[i][j - 1] == 1 &&
            r.find(make_pair(i, j - 1)) == r.end()) {
            dfs(i, j - 1, A, r);
        }
    }
};

int main() {
    vector<vector<int>> a = {
        {0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0},
        {1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1},
    };

    Solution s;
    auto x = s.numEnclaves(a);
}