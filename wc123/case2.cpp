#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>> dp(26, vector<int>(26, 0));
        /// 0: not sure; 1-> true; -1:false;

        for (int i = 0; i < 26; ++i) {
            dp[i][i] = 1;
        }

        for (auto eq : equations) {
            int v1 = eq[0] - 'a';
            int v2 = eq[3] - 'a';
            bool relation = eq[1] == '=';
            // cout << v1 << " " << v2 << " " << relation << " \n";
            if (!addtomatrix(dp, v1, v2, relation)) {
                return false;
            }
        }
        return true;
    }

    bool addtomatrix(vector<vector<int>>& dp, int v1, int v2, bool rel) {
        int res;
        if (rel) {
            res = 1;
        } else {
            res = -1;
        }
        if (dp[v1][v2] != dp[v2][v1]) {
            return false;
        } else if (dp[v1][v2] != 0 && dp[v1][v2] != res) {
            return false;
        } else {
            dp[v1][v2] = res;
            dp[v2][v1] = res;
        }
        for (int i = 0; i < 26; ++i) {
            if (dp[v1][i] == 1) {
                if (dp[i][v2] == 0) {
                    dp[i][v2] = res;
                    dp[v2][i] = res;
                } else if (dp[i][v2] != res) {
                    return false;
                }
            } else if (dp[v1][i] == -1) {
                if (res == 1) {
                    if (dp[i][v2] == 0) {
                        dp[i][v2] = -1;
                        dp[v2][i] = -1;
                    } else if (dp[i][v2] != -1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    auto a = vector<string>{"a==b", "c!=b", "a==c"};
    auto x = Solution().equationsPossible(a);
    cout << x << endl;
}