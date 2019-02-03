#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A,
                                          vector<Interval>& B) {
        int ai = 0;
        int bi = 0;
        vector<Interval> res;

        while (ai < A.size() && bi < B.size()) {
            auto ae = A[ai];
            auto be = B[bi];
            if (ae.end < be.start) {
                ++ai;
            } else if (ae.start > be.end) {
                ++bi;
            } else {
                auto _mmin = max(ae.start, be.start);
                auto _mmax = min(ae.end, be.end);
                res.push_back(Interval(_mmin, _mmax));
                if (ae.end > be.end) {
                    ++bi;
                } else {
                    ++ai;
                }
            }
        }
        return res;
    }
};