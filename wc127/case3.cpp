#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        auto t = _common(A, B);
        if (t.size() == 0) {
            return -1;
        }
        unordered_map<int, int> ma;
        unordered_map<int, int> mb;
        for (int i = 0; i < A.size(); ++i) {
            ++ma[A[i]];
            ++mb[B[i]];
        }
        int ret = INT_MAX;
        int l = A.size();
        for (auto it = t.begin(); it != t.end(); ++it) {
            ret = min(ret, l - ma[*it]);
            ret = min(ret, l - mb[*it]);
        }
        return ret;
    }

    unordered_set<int> findcommon(unordered_set<int> a, unordered_set<int> b) {
        unordered_set<int> res;
        for (auto it = a.begin(); it != a.end(); ++it) {
            if (b.find(*it) != b.end()) {
                res.insert(*it);
            }
        }
        return res;
    }

    unordered_set<int> _common(vector<int>& A, vector<int>& B) {
        // find common
        auto curcom = unordered_set<int>{A[0], B[0]};
        for (int i = 1; i < A.size(); ++i) {
            unordered_set<int> a = {A[i - 1], B[i - 1]};
            unordered_set<int> b = {A[i], B[i]};
            auto common = findcommon(a, b);
            curcom = findcommon(common, curcom);
            if (curcom.size() == 0) {
                return curcom;
            }
        }
        return curcom;
    }
};

int main() {}