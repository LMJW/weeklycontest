#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        unordered_map<char, int> res;
        for (int i = 0; i < A[0].size(); ++i) {
            ++res[A[0][i]];
        }

        for (int i = 1; i < A.size(); ++i) {
            unordered_map<char, int> cur;
            for (int j = 0; j < A[i].size(); ++j) {
                ++cur[A[i][j]];
            }
            unordered_map<char, int> nres;
            for (auto iter = cur.begin(); iter != cur.end(); ++iter) {
                auto key = iter->first;
                auto val = iter->second;
                if (res.find(key) != res.end()) {
                    nres[key] = min(res[key], val);
                }
            }
            res = nres;
        }

        vector<string> ret;
        for (auto iter = res.begin(); iter != res.end(); ++iter) {
            auto key = iter->first;
            auto val = iter->second;
            for (int i = 0; i < val; ++i) {
                string s(1, key);
                ret.push_back(s);
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<string> sss = {"bella", "label", "roller"};
    auto x = s.commonChars(sss);
    for (auto e : x) {
        cout << e << " ";
    }
}