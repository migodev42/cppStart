/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */
#include <vector>

using std::vector;

// @lc code=start
// for循环适合模拟从头到尾的遍历，而while循环适合模拟环形遍历，要善于使用while！
// 暴力法 for
// class Solution {
//  public:
//   int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//     int startPos = -1;
//     for (int i = 0; i < gas.size(); ++i) {
//       // 可以出发的加油站
//       if (gas[i] >= cost[i]) {
//         int curLeft = 0;
//         int j;
//         for( j = i; j<gas.size(); ++j){
//           curLeft += gas[j];
//           if(curLeft<cost[j]){
//             break;
//           }
//           curLeft = curLeft -cost[j];
//         }
//         if(j!=gas.size()) continue;
//         for(j =0; j<i; ++j){
//           curLeft += gas[j];
//           if(curLeft<cost[j]){
//             break;
//           }
//           curLeft = curLeft -cost[j];
//         }
//         if(j!=i) continue;
//         return i;
//       }
//     }
//     return startPos;
//   }
// };

// 暴力法 while
// class Solution {
//  public:
//   int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//     for (int i = 0; i < gas.size(); ++i) {
//       int index = (i + 1) % gas.size();
//       int curLeft = gas[i] - cost[i];
//       while (curLeft > 0 && index != i) {
//         curLeft += gas[index] - cost[index];
//         index = (index + 1) % gas.size();
//       }
//       if (curLeft >= 0 && index == i)
//         return i;
//     }
//     return -1;
//   }
// };

// 贪心法 

// @lc code=end

int main() {
  Solution s;
  vector<int> gas = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};
  s.canCompleteCircuit(gas, cost);
}