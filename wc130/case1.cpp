#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ret;
        int cur = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (i == 0) {
                cur += A[i];
                ret.push_back(cur % 5 == 0);

            } else {
                cur *= 2;
                cur += A[i];
                cur %= 5;
                ret.push_back(cur == 0);
            }
        }
        return ret;
    }
};

int main() {}