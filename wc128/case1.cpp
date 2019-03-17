#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int N) {
        vector<int> r;
        if (N == 0) {
            return 1;
        }
        while (N != 0) {
            auto t = N % 2;
            N = N / 2;
            if (t == 0) {
                r.push_back(1);
            } else {
                r.push_back(0);
            }
        }
        int ret = 0;
        int idx = 1;
        for (int i = 0; i < r.size(); ++i) {
            ret += r[i] * idx;
            idx *= 2;
        }
        return ret;
    }
};

int main() {
    Solution s;
    auto x = s.bitwiseComplement(10);
    cout << x << endl;
}