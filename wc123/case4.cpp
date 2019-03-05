#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atmostK(A, K) - atmostK(A, K - 1);
    }

    // this function calculate the total combination of subarray that less or
    // equal to K. Notice the sub array do count the same subarray. eg
    // [1,2,1,2,3] : the [1,2] will counted twice.

    // But, as we using the substraction from K to K-1, both of them will have
    // duplicated count and the substraction will deduce the repeated elements.
    int atmostK(vector<int>& A, int k) {
        int i = 0, res = 0;
        unordered_map<int, int> m;
        // here, we slide the right pointer
        // we did not control the left pointer in the outer loop. instead, we
        // use a inner while loop to slide the left pointer until we can slide
        // right pointer again.
        for (int j = 0; j < A.size(); ++j) {
            // the following if statement updates the state after we slide the
            // right pointer by 1; Here, we used the K to keep track of the
            // window size, every time we slide the right pointer, we reduce the
            // window size by 1;

            // the if statement basically says if the element is not existed in
            // the hash map, we add this new element in hash map and reduce the
            // window size by one as we increased the map size;
            if (m[A[j]] == 0) {
                --k;
            }
            // otherwise, we just add the count of the element in the hash map
            // without reducing the k as we are not adding new element.
            ++m[A[j]];

            // here, we use k to keep track of whether we need to slide the left
            // pointer. if k < 0, it means the distinct element in current
            // window is larger than the required values, hence, we need to
            // slide the left pointer until the window only contain k distinct
            // elements.
            while (k < 0) {
                // when A[i], the left pointer has count 1, we know this is the
                // last element in the window, we know for sure if we slide this
                // to right, this element will not in the window, so we reduce
                // the count by 1, ++i to shift right and add 1 to k to
                // terminate the while loop

                // else, we simply reduce the count by 1 and ++i to slide left
                // pointer to right.
                if (m[A[i]] > 1) {
                    --m[A[i]];
                    ++i;
                } else {
                    --m[A[i]];
                    ++i;
                    ++k;
                }
            }
            res += j - i + 1;
        }
        return res;
    }
};

int main() {
    vector<int> a = {1, 2, 1, 2, 3, 2, 3, 4, 2, 1, 4, 2, 3, 1, 2};
    // vector<int> a = {1, 2, 1, 2, 3};
    int x = Solution().subarraysWithKDistinct(a, 3);
    cout << x << endl;
}