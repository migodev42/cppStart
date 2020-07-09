#include <iostream>
#include <string>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    string word;
    while (cin >> word) { // 反复读取，直到到达文件末尾（或者Ctrl-D for unix/linux, Ctrl-Z for windows ）
        cout << word << endl; // 逐个输出，每个输出后换行
    }
    cout << "end" << endl;
    return 0;
}