#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct grid {
    int N;
    vector<unordered_set<int>> rows;
    vector<unordered_set<int>> cols;
    vector<unordered_set<int>> fslash;
    vector<unordered_set<int>> bslash;
    grid(int n)
        : N(n), rows(n), cols(n), fslash(2 * n - 1), bslash(2 * n - 1) {}
    void add(int x, int y) {
        rows[x].insert(y);
        cols[y].insert(x);
        int fidx = N - 1 - x + y;
        int bidx = 2 * N - 2 - x - y;
        fslash[fidx].insert(bidx);
        bslash[bidx].insert(fidx);
    }
    int query(int x, int y) {
        int fidx = N - 1 - x + y;
        int bidx = 2 * N - 2 - x - y;
        int res = 0;
        if (rows[x].size() > 0 || cols[y].size() > 0 ||
            fslash[fidx].size() > 0 || bslash[bidx].size() > 0) {
            res = 1;
        }
        closelamp(x, y);
        return res;
    }
    void closelamp(int x, int y) {
        for (int tx = -1; tx < 2; ++tx) {
            for (int ty = -1; ty < 2; ++ty) {
                int tmpx = tx + x;
                int tmpy = ty + y;
                if (tmpx > -1 && tmpx < N && tmpy > -1 && tmpy < N) {
                    _close(tmpx, tmpy);
                }
            }
        }
    }

    void _close(int x, int y) {
        if (rows[x].find(y) != rows[x].end()) {
            rows[x].erase(y);
        }
        if (cols[y].find(x) != cols[y].end()) {
            cols[y].erase(x);
        }
        int fidx = N - 1 - x + y;
        int bidx = 2 * N - 2 - x - y;
        if (fslash[fidx].find(bidx) != fslash[fidx].end()) {
            fslash[fidx].erase(bidx);
        }
        if (bslash[bidx].find(fidx) != bslash[bidx].end()) {
            bslash[bidx].erase(fidx);
        }
    }
};

class Solution {
public:
    vector<int> gridIllumination(int N,
                                 vector<vector<int>>& lamps,
                                 vector<vector<int>>& queries) {
        vector<int> res(queries.size(), 0);

        grid g(N);

        for (auto p : lamps) {
            g.add(p[0], p[1]);
        }

        for (int t = 0; t < queries.size(); ++t) {
            auto q = queries[t];
            res[t] = g.query(q[0], q[1]);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> lp = {vector<int>{0, 0}, vector<int>{4, 4}};
    vector<vector<int>> qs = {vector<int>{1, 1}, vector<int>{1, 0}};
    auto x = s.gridIllumination(5, lp, qs);
    for (auto p : x) {
        cout << p << endl;
    }
}