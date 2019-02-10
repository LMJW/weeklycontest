#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res(20000, 0);
        int idx = A.size() - 1;
        int carry = 0;
        int residx = res.size() - 1;
        while (K > 0 || idx >= 0) {
            int dig = K % 10;
            int t;
            K /= 10;
            if (idx >= 0) {
                t = A[idx] + dig + carry;
            } else {
                t = dig + carry;
            }

            if (t >= 10) {
                carry = t / 10;
                t = t % 10;
            } else {
                carry = 0;
            }
            res[residx] = t;
            --residx;
            --idx;
        }
        for (auto it = res.begin(); it != res.end(); ++it) {
            if (*it == 0) {
                continue;
            }
            auto newres = vector<int>(it, res.end());
            return newres;
        }
        return res;
    }
};

int main() {}