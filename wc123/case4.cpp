#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int i = 0;
        unordered_map<int, int> hash;
        int count = 0;
        int cur = 1;

        for (int j = 0; j < A.size(); ++j) {
            if (hash.find(A[j]) == hash.end()) {
                hash[A[j]] = 1;
            } else {
                ++hash[A[j]];
            }
            if (hash.size() < K) {
                cur = 1;
            } else if (hash.size() == K) {
                while (hash[A[i]] > 1) {
                    --hash[A[i]];
                    ++i;
                    ++cur;
                }
                count += cur;
            } else if (hash.size() > K) {
                hash.erase(A[i]);
                ++i;
                cur = 1;
                while (hash[A[i]] > 1) {
                    --hash[A[i]];
                    ++i;
                    ++cur;
                }
                count += cur;
            }
        }
        return count;
    }
};

int main() {
    // vector<int> a = {1, 2, 1, 2, 3, 2, 3, 4, 2, 1, 4, 2, 3, 1, 2};
    vector<int> a = {1, 2, 1, 2, 2, 2, 3, 1, 3};
    int x = Solution().subarraysWithKDistinct(a, 3);
    cout << x << endl;
}