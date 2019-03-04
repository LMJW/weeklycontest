#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, j = 0, max_val = 0, cur_val = 0, cur_k = K;
        // finish condition
        while (i < A.size() || j < A.size()) {
            // try to slide the right pointer until it cannot slide anymore
            // then slide left until right can slide again
            // after each slide, we update some state
            if (j < A.size() && (A[j] == 1 || cur_k > 0)) {
                if (A[j] == 1) {
                    ++j;
                    ++cur_val;
                } else if (cur_k > 0) {
                    ++j;
                    ++cur_val;
                    --cur_k;
                }
                // slide the left pointer
            } else {
                if (i < A.size() && A[i] == 0) {
                    ++cur_k;
                    --cur_val;
                } else {
                    --cur_val;
                }
                ++i;
            }
            // evaluate the result
            max_val = max(max_val, cur_val);
        }
        return max_val;
    }
};

int main() {
    Solution s;
    vector<int> a = {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1};
    auto x = s.longestOnes(a, 0);
    cout << x << "!";
}