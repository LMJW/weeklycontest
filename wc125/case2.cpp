#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        // find rook
        int r, c;

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'R') {
                    r = i;
                    c = j;
                }
            }
        }
        int count = 0;
        // check 4 directions
        // check left
        for (int i = 1; c - i >= 0; ++i) {
            if (board[r][c - i] == 'p') {
                ++count;
                break;
            } else if (board[r][c - i] == 'B') {
                break;
            }
        }

        // check right
        for (int i = 1; c + i < 8; ++i) {
            if (board[r][c + i] == 'p') {
                ++count;
                break;
            } else if (board[r][c + i] == 'B') {
                break;
            }
        }

        // check top
        for (int i = 1; r + i < 8; ++i) {
            if (board[r + i][c] == 'p') {
                ++count;
                break;
            } else if (board[r + i][c] == 'B') {
                break;
            }
        }

        // check right
        for (int i = 1; r - i >= 0; ++i) {
            if (board[r - i][c] == 'p') {
                ++count;
                break;
            } else if (board[r - i][c] == 'B') {
                break;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    // s.numRookCaptures()
}