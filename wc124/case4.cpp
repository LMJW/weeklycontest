#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct myhashvec {
    vector<int> v;
    myhashvec(vector<int> vv) : v(vv) {}

    bool operator==(const myhashvec& other) const {
        if (v.size() == other.v.size()) {
            for (int i = 0; i < v.size(); ++i) {
                if (v.at(i) != other.v.at(i)) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};

template <>
struct hash<myhashvec> {
    size_t operator()(const myhashvec& m) const {
        auto res = hash<int>()(13);
        for (auto it = m.v.begin(); it != m.v.end(); ++it) {
            res ^= (hash<int>()(*it) << 1);
        }
        return res;
    }
};

class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        /// @param used stores the index of the used values
        /// @param store stores all the possible valid combination
        unordered_set<myhashvec> store;

        for (int i = 0; i < A.size(); ++i) {
            unordered_set<int> used;
            used.insert(i);
            vector<int> tmp;
            tmp.push_back(A[i]);
            _dfs(tmp, store, used, A);
        }

        /// ugly solution
        /// ugly solution wouldn't work
        int count = 0;
        for (auto it = store.begin(); it != store.end(); ++it) {
            if (it->v.size() == A.size()) {
                ++count;
            }
        }

        return count;
    }

    /// Calculate whether the sum of two number is sqareful root
    bool check(int x, int y) {
        int sum = x + y;
        auto t = sqrt(sum);
        return int(t) * int(t) == sum;
    }

    void _dfs(vector<int> path,
              unordered_set<myhashvec>& store,
              unordered_set<int> used,
              const vector<int>& A) {
        /// assume path length > 0
        auto t = myhashvec(path);
        if (store.find(t) == store.end()) {
            int last_ele = path.back();
            if (path.size() < A.size()) {
                for (int i = 0; i < A.size(); ++i) {
                    unordered_set<int> cpused(used);
                    if (cpused.find(i) == cpused.end() &&
                        check(last_ele, A[i])) {
                        vector<int> nv(path);
                        nv.push_back(A[i]);
                        cpused.insert(i);
                        _dfs(nv, store, cpused, A);
                    }
                }
                store.insert(myhashvec(path));
            } else if (path.size() == A.size()) {
                store.insert(myhashvec(path));
            } else {
                throw "haha, wrong";
            }
        }
    }
};

int main() {
    vector<int> a = vector<int>{0, 0, 0, 0, 1, 1, 1, 1};
    auto x = Solution().numSquarefulPerms(a);
    cout << x << endl;
}