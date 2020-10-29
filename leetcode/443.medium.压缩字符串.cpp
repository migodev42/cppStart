#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::to_string;
using std::cout;
using std::endl;
class Solution {
public:
    int process(vector<char>& chars, int cstart, int repeat) {
        if(repeat==0) return cstart+1;
        string s = to_string(repeat+1);
        for (int i = 0; i < s.size(); ++i) {
            chars[cstart + 1 + i] = s[i];
        }
        auto new_cstart = cstart + 1 + s.size();
        if (repeat > s.size()) {
            auto endof_num = chars.begin() + new_cstart;
            auto endof_repeat = chars.begin() + cstart + repeat;
            // endof_num+1 从数值之后一位开始 endof_repeat+1 是下一个cstartc
            // 左闭右开
            chars.erase(endof_num, endof_repeat+1);
        }
        return new_cstart;
    }
    int compress(vector<char>& chars) {
        if (chars.empty()) return 0;
        int repeat = 0;
        int cstart = 0, cmove = 0;

        while (cmove < chars.size()) {
            ++cmove;
            if (cmove != chars.size() && chars[cmove] == chars[cstart]) {
                ++repeat;
            }
            else {
                auto newstart = process(chars, cstart, repeat);                
                repeat = 0;
                cstart = newstart;
                cmove = newstart;
            }
        }        
        return chars.size();
    }
};

int main() {
    Solution s;
    vector<char> chars = { 'a','a','b','b','b','b','b','c','c','c' };
    s.compress(chars);
}