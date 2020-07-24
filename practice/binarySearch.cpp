#include <iostream>
#include <string>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    /* text为一个有序序列 */
    string text = {"abcdefghijklmnopqrstuvwxyz"};

    char target = 'y';

    /* beg为迭代器的头， end为迭代器的尾 */
    auto beg = text.begin(), end = text.end();

    /* mid为迭代器的中间位置 */
    auto mid = beg + (end - beg) / 2;

    while (target != *mid && beg != end) {
        cout << target << " vs " << *mid << endl;
        if (target > *mid) {
            beg = mid;
        } else {
            end = mid - 1;
        }
        mid = beg + (end - beg) / 2;
    }

    cout << "rs:" << target << " vs " << *mid << endl;
    return 0;
}
