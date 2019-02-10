#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct disjointset {
    disjointset() {}
    unordered_map<int, int> ds;
    unordered_set<int> ueq;
    bool addequal(int v1, int v2) {
        int p1 = parent(v1);
        int p2 = parent(v2);
        if (ueq.find(p1) != ueq.end() && ueq.find(p2) != ueq.end()) {
            return false;
        }
        ds[p1] = p2;
        return true;
    }
    bool add_unequal(int v1, int v2) {
        int p1 = parent(v1);
        int p2 = parent(v2);
        if (p1 == p2) {
            return false;
        }
        ueq.insert(p1);
        ueq.insert(p2);
        return true;
    }
    int parent(int v) {
        if (ds.find(v) == ds.end()) {
            ds[v] = v;
            return ds[v];
        }

        while (ds[v] != v) {
            v = ds[v];
        }
        return ds[v];
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        /// we can use disjoint set to get a clean solution?
        /// equality can be stored in a disjoint set
        /// How can i store a!=b, a!=c, a!=d?
        disjointset ds;

        for (auto eq : equations) {
            int v1 = eq[0] - 'a';
            int v2 = eq[3] - 'a';
            bool relation = eq[1] == '=';
            // cout << v1 << " " << v2 << " " << relation << " \n";
            if (!addtoset(ds, v1, v2, relation)) {
                return false;
            }
        }
        return true;
    }

    bool addtoset(disjointset& ds, int v1, int v2, bool rel) {
        if (rel) {
            if (!ds.addequal(v1, v2)) {
                return false;
            }
        } else {
            if (!ds.add_unequal(v1, v2)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    auto a = vector<string>{"a==b", "c==b", "a==c"};
    auto x = Solution().equationsPossible(a);
    cout << x << endl;
}