#include <iostream>
#include <vector>

int main() {
    using std::cout;
    using std::endl;
    using std::vector;

    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &i : v) {
        i *= i; // v中每个元素取平方
    }

    for (auto i : v) {
        cout << i << " "; // 输出v中每个元素
    }
    cout << endl;
    return 0;
}
