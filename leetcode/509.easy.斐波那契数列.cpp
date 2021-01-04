

/* 自底向上-动态规划 */
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int pre = 0;
        int curr = 1;
        for (int i = 2;i <= n;++i) {
            int tmp = curr;
            curr = curr + pre;
            pre = tmp;
        }
        return curr;
    }
};

/* 普通递归 */
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
};

/* 递归-备忘录法 */

