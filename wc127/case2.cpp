#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int clumsy(int N) {
        int res = 0;
        res += _rec(N, 1);
        while (N > 0) {
            res -= _rec(N, -1);
        }
        return res;
    }

    int _rec(int& n, int c) {
        int res;
        if (n >= 3) {
            res = n * (n - 1) / (n - 2) + c * (n - 3);
            n -= 4;
            return res;
        } else {
            res = n;
            n = 0;
            return res;
        }
    }
};

int main() {
    Solution s;
    auto x = s.clumsy(4);
    cout << x;
}