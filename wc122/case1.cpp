#include <iostream>

#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A,
                                    vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> res;
        for (auto e : A) {
            if (e % 2 == 0) {
                sum += e;
            }
        }

        for (auto q : queries) {
            auto v = q[0];
            auto idx = q[1];
            auto t = A[idx];
            if (t % 2 == 0) {  /// t is even
                if (v % 2 == 0) {
                    A[idx] += v;
                    sum += v;
                } else {
                    A[idx] += v;
                    sum -= t;
                }
            } else {  /// t is odd
                if (v % 2 == 0) {
                    A[idx] += v;
                } else {
                    A[idx] += v;
                    sum += A[idx];
                }
            }
            res.push_back(sum);
        }
        return res;
    }
};

int main() {
    Solution s;
}