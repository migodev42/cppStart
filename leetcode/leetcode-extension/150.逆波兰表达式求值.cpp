/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using std::stack;
using std::string;
using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string, bool> optchar = {
            {"+", true},
            {"-", true},
            {"*", true},
            {"/", true},
        };
        for (int i = 0; i < tokens.size(); ++i) {
            string curr = tokens[i];
            if (optchar[curr]) {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(num2 + num1);
                if (tokens[i] == "-") st.push(num2 - num1);
                if (tokens[i] == "*") st.push(num2 * num1);
                if (tokens[i] == "/") st.push(num2 / num1);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        int result = st.top();
        st.pop();
        return result;
    }
};
// @lc code=end
