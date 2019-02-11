#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int brokenCalc(int x, int y) {
        if (x >= y) {
            return x - y;
        }
        unordered_set<int> hist;
        int count = 0;
        vector<int> cur = {x};

        while (true) {
            vector<int> nl;
            ++count;
            for (auto e : cur) {
                if (e < y) {
                    int t = e * 2;
                    if (t == y) {
                        return count;
                    }
                    if (hist.find(t) == hist.end()) {
                        hist.insert(t);
                        nl.push_back(t);
                    }
                }
                int t = e - 1;
                if (t == y) {
                    return count;
                }
                if (t > 0 && hist.find(t) == hist.end()) {
                    hist.insert(t);
                    nl.push_back(t);
                }
            }
            cur = nl;
        }
    }
};

int main() {
    int x = Solution().brokenCalc(1, 10000000);
    cout << x << " ";
}