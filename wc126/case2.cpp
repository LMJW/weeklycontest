#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const long long PRIMAR = 1000000007;
const long long multi = 31;
const long long multiq = 31 * 31 * 31;

size_t hashstr(string& s, int start) {
    long long res = 0;
    for (int i = start + 2; i >= start; --i) {
        res = (res + static_cast<int>(s[i])) * multi % PRIMAR;
    }
    return res;
}

class Solution {
public:
    bool isValid(string S) {
        string sss = "abc";
        auto abc = hashstr(sss, 0);
        if (S[0] != 'a' || S.size() < 3) {
            return false;
        }

        while (S.size() > 0) {
            int begin = S.size();
            int end = S.size() - 1;
            for (int i = 0; i < S.size() - 2; ++i) {
                auto t = hashstr(S, i);
                if (t == abc) {
                    S.erase(i, 3);
                    break;
                }
            }
            if (begin == S.size()) {
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution s;

    auto x = s.isValid("abcabcababcc");
}