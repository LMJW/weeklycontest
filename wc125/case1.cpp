#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        // key->target, val-> count
        vector<unordered_set<int>> tc(N + 1);
        vector<unordered_set<int>> c(N + 1);
        for (auto p : trust) {
            auto a = p[0];
            auto b = p[1];

            if (b != a) {
                tc[b].insert(a);
            }
            c[a].insert(b);
        }

        for (int i = 1; i < N + 1; ++i) {
            if (tc[i].size() == N - 1 && c[i].size() == 0) {
                return i;
            }
        }
        return -1;
    }
};

int main() {}