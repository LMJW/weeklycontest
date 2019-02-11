#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int brokenCalc(int x, int y) {
        int count = 0;
        while (y > x) {
            if (y % 2 == 0) {
                y /= 2;
            } else {
                ++y;
            }
            ++count;
        }
        return count + x - y;
    }
};

int main() {
    int x = Solution().brokenCalc(1, 10000000);
    cout << x << " ";
}