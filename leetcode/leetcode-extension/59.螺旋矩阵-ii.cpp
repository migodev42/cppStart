/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

 // @lc code=start
#include <vector>

using std::vector;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    int loop = n / 2;
    int startX, startY = 0;
    int count = 1; // 用来给矩阵中每一个空格赋值，用于填充的数
    int mid = n / 2;
    int offset = 1;
    int row, col;

    while (loop--) {
      row = startX;
      col = startY;

      /* 上行 左->右 */
      for (col = startY; col < startY + n - offset; ++col) {
        result[startX][col] = count++;
      }

      /* 右行 上->下 */
      for (row = startX;row < startX + n - offset; ++row) {
        result[row][startY + n - offset] = count++;
      }

      /* 下行 右->左 */
      for (;col > startY; --col) {
        result[row][col] = count++;
      }

      /* 左行 下->上 */
      for (;row > startX; --row) {
        result[row][col] = count++;
      }
      offset+=2;
      ++startX;
      ++startY;
    }
    

    // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
    if (n % 2) {
      result[mid][mid] = count;
    }
    return result;
  }
};
// @lc code=end

