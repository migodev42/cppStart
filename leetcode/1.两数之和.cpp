#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::to_string;
using std::stoi;
/*
    [2,7,11,15]
    9
 */
vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> cache;
    cache[nums[0]] = 0;
    vector<int> rs;
    for (std::vector<int>::size_type i = 1; i < nums.size();++i) {
        int cur = nums[i];
        if (cache.find(target - cur) != cache.end()) {
            int pos0 = cache[target - cur];
            int pos1 = static_cast<int>(i);
            rs = { pos0, pos1 };
            return rs;
        }
        cache[cur] = i;
    }
    return rs;
}

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    vector<int> inputNums = { 2,7,11,15 };
    int inputTarget = 9;
    vector<int> rs = twoSum(inputNums, inputTarget);
    for (auto item : rs) {
        cout << item << endl;
    }
    return 0;
}
