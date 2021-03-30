/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include <unordered_map>
#include <utility>
#include <vector>
#include <queue>

using std::priority_queue;
using std::pair;
using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
   private:
    class MyComparison {
       public:
        bool operator()(const pair<int, int>& l, const pair<int, int>& r) {
            return l.second > r.second;
        }
    };

   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> store;  // 用于统计元素出现的次数
        for (int i = 0; i < nums.size(); ++i) {
            ++store[nums[i]];
        }
        
        // 定义一个堆(优先级队列，此处应该使用小顶堆)
        priority_queue<pair<int,int>,vector<pair<int,int>>,MyComparison> p_que;

        // 用固定大小为k的小顶堆，遍历所有频率的数值
        for(auto i = store.begin(); i!=store.end();++i){
          p_que.push(*i);
          if(p_que.size()>k){
            p_que.pop();
          }
        }
        vector<int> result;
        while(!p_que.empty()){
          int item = p_que.top().first;
          p_que.pop();
          result.push_back(item);
        }
        return result;
    }
};
// @lc code=end
