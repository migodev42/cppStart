#include <iostream>
#include <vector>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::vector;

    /* 以10分为一个区间统计每一个区间的成绩数量 */
    vector<unsigned> scoreCnt(10, 0);   // 初始化每个区间的分数计数为0
    unsigned input = 0;
    while (cin >> input) {              // 输入成绩
        if(input<=100){                 // 只统计有效成绩
            ++scoreCnt[input/10]        // 将对应区间成绩计数+1
        }
    }

    cout << "Hello Wolrd\n";
    return 0;
}
