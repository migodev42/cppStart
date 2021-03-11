/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
   private:
    vector<int> origin;

   public:
    Solution(vector<int>& nums) : origin(nums) {
      // srand((unsigned)time(nullptr));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() { return origin; }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {        
        int randidx = 0;
        vector<int> shuffled(origin.begin(), origin.end());
        for (int i = 0; i < shuffled.size(); ++i) {
            randidx = i + rand() % (shuffled.size() - i);
            // 
            swap(shuffled[i], shuffled[randidx]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
