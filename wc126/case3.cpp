#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, max_val = 0, cur_val = 0;
        // for loop indicate we slide the right window
        for (int j = 0; j < A.size(); ++j) {
            // more consice version of solution
            if (A[j] == 0)
                --K;

            // Here, there is no while loop to shift the left pointer as the
            // current algorithm only care the largest one.
            if (K < 0) {
                if (A[i] == 0)
                    ++K;
                ++i;
            }
            max_val = max(max_val, j - i + 1);
            // K -= A[j] == 0;
            // if (K < 0 && A[i++] == 0)
            //     K++;
            // max_val = max(max_val, j - i + 1);
        }
        return max_val;
    }
};

int main() {
    Solution s;
    vector<int> a = {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1};
    auto x = s.longestOnes(a, 2);
    cout << x << "!";
}