#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct disjointset {
    disjointset() {}
    unordered_map<int, int> ds;
    void addequal(int v1, int v2) {
        int p1 = parent(v1);
        int p2 = parent(v2);
        ds[p1] = p2;
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
    bool check_eq(int v1, int v2) {
        int p1 = parent(v1);
        int p2 = parent(v2);
        if (p1 == p2) {
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        /// we can use disjoint set to get a clean solution?
        /// equality can be stored in a disjoint set
        /// How can i store a!=b, a!=c, a!=d?
        disjointset ds;
        vector<string> eqs_not_equal;

        for (auto eq : equations) {
            int v1 = eq[0] - 'a';
            int v2 = eq[3] - 'a';

            bool relation = eq[1] == '=';
            // cout << v1 << " " << v2 << " " << relation << " \n";
            if (relation) {
                addtoset(ds, v1, v2);
            } else {
                eqs_not_equal.push_back(eq);
            }
        }
        for (auto eq : eqs_not_equal) {
            int v1 = eq[0] - 'a';
            int v2 = eq[3] - 'a';
            if (ds.check_eq(v1, v2)) {
                return false;
            }
        }

        return true;
    }

    void addtoset(disjointset& ds, int v1, int v2) { ds.addequal(v1, v2); }
};

int main() {
    // auto a = vector<string>{"a!=b", "c!=d", "a==c"};
    auto a = vector<string>{"a!=b", "c!=d", "a==c", "b==c"};
    // auto a = vector<string>{"e==d", "e==a", "f!=d", "b!=c", "a==b"};
    auto x = Solution().equationsPossible(a);
    cout << x << endl;
}