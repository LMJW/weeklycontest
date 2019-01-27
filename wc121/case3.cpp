#include <iostream>
#include <vector>

using namespace std;

const int MAX_COST = 1001;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int l = days.size();

        vector<int> dp(days[l - 1] + 1, 0);
        vector<int> ticket = {1, 7, 30};

        for (int j = 1; j < dp.size(); ++j) {
            int cmin = MAX_COST;
            cout << j << "::";
            for (int i = 0; i < 3; i++) {
                int cur = MAX_COST;
                int last = j - ticket[i];
                if (last < 0) {
                    cur = costs[i];
                } else {
                    cur = dp[last] + costs[i];
                }

                if (cur < cmin) {
                    cmin = cur;
                }
                cout << cur << " ";
            }
            dp[j] = cmin;
            cout << " |" << cmin << " \n";
        }
        return dp[l];
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