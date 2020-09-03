#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;
using std::cout;
/*
    组合 Cnm
    n!/(n-m)!m!
*/

int numIdenticalPairs(vector<int>& nums) {
    unordered_map<int, int> m;
    for (decltype(num.size()) i = 0; i < nums.size();++i) {
        ++m[nums[i]];
    }
    int ans = 0;
    for (const auto& [k, v] : m) {
        ans += v * (v - 1) / 2;
    }
    return ans;

}

int main() {
    using std::cout;
    using std::cin;
    using std::endl;


    vector<int> v = { 6,5,1,5,7,7,9,1,5,7,1,6,10,9,7,4,1,8,7,1,1,8,6,4,7,4,10,5,3,9,10,1,9,5,5,4,1,7,4,2,9,2,6,6,4,2,10,3,5,3,6,4,7,4,6,4,4,6,3,4,10,1,10,6,10,4,9,6,6,4,8,6,9,5,4 };
    int rs = numIdenticalPairs(v);
    cout << "rs: " << rs << endl;
    return 0;
}
