#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;

        int height = grid.size();
        int width = grid[0].size();
        int rs = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == 1){
                    rs += 4;
                    if (i != 0 && grid[i - 1][j] == 1) rs -= 2;
                    if (j != 0 && grid[i][j - 1] == 1) rs -= 2;
                } 
                
            }
        }
        return rs;
    }
};

int main() {
    // vector<vector<int>> grid = { {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0} };
    vector<vector<int>> grid = {{1, 0}};
    Solution s;
    int rs = s.islandPerimeter(grid);
    cout << rs << endl;
}