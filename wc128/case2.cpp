#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> k(60);
        int count = 0;
        for (auto t : time) {
            t %= 60;
            count += k[(60 - t) % 60];
            ++k[t];
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> t = {60, 60, 60};
    auto x = s.numPairsDivisibleBy60(t);
    cout << x << endl;
}