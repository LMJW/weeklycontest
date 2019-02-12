#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int i = 0;
        int j = 0;
        unordered_map<int, int> hash;
        hash.insert({A[j], 1});
        int count = 0;
        while (i < A.size() && j < A.size()) {
            if (hash.size() == K) {
                int cur = 1;
                while (hash[A[i]] > 1) {
                    --hash[A[i]];
                    ++i;
                    ++cur;
                }
                count += cur;
                while (j + 1 < A.size() && hash.find(A[j + 1]) != hash.end()) {
                    ++hash[A[j + 1]];
                    if (A[j + 1] == A[i]) {
                        ++cur;
                        ++i;
                        while (hash[A[i]] > 1) {
                            --hash[A[i]];
                            ++i;
                            ++cur;
                        }
                    }
                    count += cur;
                    ++j;
                }
                if (j == A.size() - 1) {
                    return count;
                }
                hash[A[j]] = 1;
                hash.erase(A[i]);
                ++i;
            } else if (hash.size() < K) {
                ++j;
                if (hash.find(A[j]) == hash.end()) {
                    hash[A[j]] = 1;
                } else {
                    ++hash[A[j]];
                }
            } else {
                cout << "wrong path\n" << endl;
            }
        }
        return count;
    }
};

int main() {
    vector<int> a = {1, 2, 1, 2, 3, 2, 3, 4, 2, 1, 4, 2, 3, 1, 2};
    int x = Solution().subarraysWithKDistinct(a, 3);
    cout << x << endl;
}