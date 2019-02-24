#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct point {
    int x, y;
    point(int x, int y) : x(x), y(y) {}
    friend bool operator==(const point& p1, const point& p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }
};

template <>
struct hash<point> {
    std::size_t operator()(const point& p) const {
        return (hash<int>()(p.x) ^ (hash<int>()(p.y) >> 1));
    }
};

struct grid {
    int N;
    unordered_map<int, int> rows;
    unordered_map<int, int> cols;
    unordered_map<int, int> fslash;
    unordered_map<int, int> bslash;
    unordered_map<point, int> lmap;

    grid(int n) : N(n) {}
    void add(int x, int y) {
        lmap[point(x, y)] = 1;
        if (rows.find(x) == rows.end()) {
            rows[x] = 1;
        } else {
            ++rows[x];
        }
        if (cols.find(y) == cols.end()) {
            cols[y] = 1;
        } else {
            ++cols[y];
        }
        int fidx = N - 1 - x + y;
        if (fslash.find(fidx) == fslash.end()) {
            fslash[fidx] = 1;
        } else {
            ++fslash[fidx];
        }
        int bidx = 2 * N - 2 - x - y;

        if (bslash.find(bidx) == bslash.end()) {
            bslash[bidx] = 1;
        } else {
            ++bslash[bidx];
        }
    }
    int query(int x, int y) {
        int fidx = N - 1 - x + y;
        int bidx = 2 * N - 2 - x - y;
        int res = 0;
        if (rows[x] > 0 || cols[y] > 0 || fslash[fidx] > 0 ||
            bslash[bidx] > 0) {
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
        auto p = point(x, y);
        if (lmap[p] == 1) {
            --rows[x];
            --cols[y];
            int fidx = N - 1 - x + y;
            int bidx = 2 * N - 2 - x - y;
            --fslash[fidx];
            --bslash[bidx];
            lmap[p] = 0;
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
    vector<vector<int>> qs = {vector<int>{1, 1}, vector<int>{1, 1}};
    auto x = s.gridIllumination(5, lp, qs);
    for (auto p : x) {
        cout << p << endl;
    }
}