#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int count = 0;
        int i = 0;
        for (; i < K; ++i) {
            if (A[i] < 0) {
                A[i] = -A[i];
                ++count;
            } else {
                break;
            }
        }
        int rest = K - count;

        int res = accumulate(A.begin(), A.end(), 0);
        if (A[i] == 0 || rest <= 0 || rest % 2 == 0) {
            return res;
        } else {
            int x = 0;
            if (i > 0) {
                x = min(A[i], A[i - 1]);
            } else {
                x = A[i];
            }
            res -= 2 * x;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> a = {3, -1, 0, 2};
    auto mm = s.largestSumAfterKNegations(a, 3);
    cout << mm << endl;
}