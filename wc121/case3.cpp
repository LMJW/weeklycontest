#include <iostream>
#include <vector>

using namespace std;

const int MAX_COST = 1001;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int l = days.size();

        vector<int> dp(days[l - 1] + 1, 0);
        vector<bool> travel(days[l - 1] + 1, false);
        vector<int> ticket = {1, 7, 30};

        for (int j = 0; j < days.size(); ++j) {
            travel[days[j]] = true;
        }

        for (int i = 1; i < dp.size(); ++i) {
            if (travel[i]) {
                int cmin = MAX_COST;

                for (int t = 0; t < 3; ++t) {
                    int last = i - ticket[t];
                    int cur;
                    if (last < 0) {
                        cur = costs[t];
                    } else {
                        cur = dp[last] + costs[t];
                    }

                    if (cur < cmin) {
                        cmin = cur;
                    }
                }

                dp[i] = cmin;
            } else {
                dp[i] = dp[i - 1];
            }
            // cout << i << ": " << dp[i] << " \n";
        }

        return dp[days[l - 1]];
    }
};

// [1,4,6,9,10,11,12,13,14,15,16,17,18,20,21,22,23,27,28]
// [3,13,45]
int main() {
    Solution s;
    vector<int> days = {1,  4,  6,  9,  10, 11, 12, 13, 14, 15,
                        16, 17, 18, 20, 21, 22, 23, 27, 28};
    vector<int> costs = {3, 13, 45};
    auto res = s.mincostTickets(days, costs);
    cout << res << "\n";
}