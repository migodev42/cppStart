#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;


class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> store;
        store[nums[0]] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int to_find = target - nums[i];
            if (store.find(to_find) != store.end()) {
                return vector<int>({store[to_find], i});
            } else {
                store[nums[i]] = i;
            }
        }
        return vector<int>();
    }
};


int main(){
  
}
