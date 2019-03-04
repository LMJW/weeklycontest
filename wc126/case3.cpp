#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, max_val = 0, cur_val = 0, cur_k = K;
        // for loop indicate we slide the right window
        for (int j = 0; j < A.size(); ++j) {
            // After the right window slided, we need to make sure the states
            // has been updated properly.
            if (A[j] == 1) {
                ++cur_val;
            } else if (cur_k > 0) {
                ++cur_val;
                --cur_k;
            } else {
                // In this part, we need to make sure the left window slide
                // properly so that after this step finishes, we can slide the
                // right pointer.

                // if the execution falls in this part, it means that current
                // pointer j is not a valid slide;
                // In this question, we can see the condition for j fall in this
                // part is because of the fact that (A[j]= 0 && cur_k = 0). So
                // in this part, we need to slide the left pointer so that the
                // last right slide becomes a valid slide.

                // To makes the last right slide to be a valid slide, we need to
                // know why it is not valid. It's simply because we run out of
                // flip and the last slide is zero. To make last right slide a
                // valid right slide, we need to slide the left util we have a
                // least a flip or left pointer reach to the right pointer.

                // When we sliding the left pointer, we need to think about the
                // update of the current state. when we slide the left pointer
                // to right, we have only to choices, either be 0 or 1. It
                // doesn't matter which we slide left, the total count will
                // always reduce by one. However, the number of flip will only
                // increase by 1 if the pointer A[i]= 0;

                // Hence, we can come out the following algorithm

                // condition: we continue slide left pointer to right if left
                // pointer is less than the right pointer and if we do not have
                // a flip
                while (i < j && cur_k < 1) {
                    // i-th element is the element we will slide through, hence,
                    // if A[i] is 0, it means by removing it we get a flip that
                    // can be used for A[j] element
                    if (A[i] == 0) {
                        // here, as we explained, the reason why we fall here is
                        // because the right pointer A[j]= 0 && cur_k = 0;
                        //
                        // we can add cur_k by 1 and then distract by 1 to
                        // indicate the A[j] used this flip, and the total value
                        // of cur_val will not change; So here we just need to
                        // slide the i to right, and then we can continue right
                        // slide.
                        ++i;
                        break;
                        // the equivalent complex version is like:
                        // //-------
                        // ++cur_k; // for sliding the A[i]
                        // --cur_val; // result of sliding left pointer to right
                        // --cur_k; // for compensate the A[j]
                        // ++cur_val; // result of A[j] fliping
                        // ++i; // indicate the left pointer sliding right
                        // break; // as we finished left slidng and it will
                        // satisfy the right sliding
                    }
                    ++i;        // whenever we slide left, we need to add i
                    --cur_val;  // and we need to reduce the value of cur_val
                }
            }
            max_val = max(max_val, cur_val);
        }
        return max_val;
    }
};

int main() {
    Solution s;
    vector<int> a = {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1};
    auto x = s.longestOnes(a, 0);
    cout << x << "!";
}