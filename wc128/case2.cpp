#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        // 1. for every number, module 60
        // use map[int, vector<int>]
        // key -> value
        // val -> vector of index
        map<int, vector<int>> hash;
        for (int i = 0; i < time.size(); ++i) {
            time[i] %= 60;
            hash[time[i]].push_back(i);
        }

        // each time, get its pair
        int count = 0;
        for (int i = 0; i < time.size(); ++i) {
            auto d = (60 - time[i]) % 60;
            if (hash.find(d) != hash.end()) {
                auto v = hash[d];
                for (int j = 0; j < v.size(); ++j) {
                    if (v[j] > i) {
                        ++count;
                    }
                }
            }
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