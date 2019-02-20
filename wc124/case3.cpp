#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int count = 0;
        for (int i = 0; i <= A.size() - K; ++i) {
            if (A[i] == 0) {
                for (int j = 0; j < K; ++j) {
                    A[i + j] = (A[i + j] + 1) % 2;
                }
                ++count;
            }
        }
        for (auto iter = A.begin(); iter != A.end(); ++iter) {
            if (*iter == 0) {
                return -1;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> a = {0, 1, 0};
    int x = s.minKBitFlips(a, 1);
    cout << x << endl;
}
