#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int count = 0;
        auto cur = head;
        while (cur->next != NULL) {
            ++count;
            cur = cur->next;
        }
        vector<int> ret(count + 1);

        stack<pair<int, int>> s;
        int idx = 0;
        while (head != NULL) {
            if (s.empty()) {
                s.push(make_pair(head->val, idx));
            } else {
                while (!s.empty()) {
                    auto t = s.top();
                    if (head->val > t.first) {
                        ret[t.second] = head->val;
                    }
                    s.pop();
                }
                s.push(make_pair(head->val, idx));
            }
            head = head->next;
            ++idx;
        }
        return ret;
    }
};

int main() {
    Solution s;
}