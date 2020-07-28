#include <iostream>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    /* 统计0-9， 10-20...90-99,100 11个分数段 */
    unsigned scores[11] = {}; // 11个分数段，全部初始化为0
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100) {
            ++scores[grade / 10];
        }
    }
    cout << endl << "统计中..." << endl;

    cout << "范围for:" << endl;
    for (int i : scores) {
        cout << i << " ";
    }

    cout << endl << "指针:" << endl;
    unsigned *pend = &scores[11];       // scores[11]取的是第12个元素
    for (unsigned *pa = &scores[0]; pa != pend; ++pa) {
        cout << *pa << " ";
    }

    cout << endl;
    return 0;
}
