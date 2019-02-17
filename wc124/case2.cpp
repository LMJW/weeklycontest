#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int lx = grid.size();
        int ly = grid[0].size();
        int all_oranges = 0;
        // calculate all oranges
        int count = 0;  // number of rotaten oranges

        vector<pair<int, int>> r_org;
        for (int i = 0; i < lx; ++i) {
            for (int j = 0; j < ly; ++j) {
                if (grid[i][j] != 0) {
                    ++all_oranges;
                    if (grid[i][j] == 2) {
                        ++count;
                        r_org.push_back(make_pair(i, j));
                    }
                }
            }
        }
        int step = 0;
        _bfs(grid, lx, ly, count, step, r_org);
        if (count < all_oranges) {
            return -1;
        }
        return step;
    }
    // pair -> steps to roat all orange ; total roted organge
    void _bfs(vector<vector<int>>& grid,
              int& gx,
              int& gy,
              int& count,
              int& step,
              vector<pair<int, int>> start) {
        vector<pair<int, int>> ns;
        for (auto it = start.begin(); it != start.end(); ++it) {
            auto x = it->first;
            auto y = it->second;
            if (x + 1 < gx && grid[x + 1][y] == 1) {
                grid[x + 1][y] = 2;
                ++count;
                ns.push_back(make_pair(x + 1, y));
            }
            if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                grid[x - 1][y] = 2;
                ++count;
                ns.push_back(make_pair(x - 1, y));
            }
            if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                grid[x][y - 1] = 2;
                ++count;
                ns.push_back(make_pair(x, y - 1));
            }
            if (y + 1 < gy && grid[x][y + 1] == 1) {
                grid[x][y + 1] = 2;
                ++count;
                ns.push_back(make_pair(x, y + 1));
            }
        }
        ++step;
        if (ns.size() > 0) {
            _bfs(grid, gx, gy, count, step, ns);
        }
    }
};

int main() {}