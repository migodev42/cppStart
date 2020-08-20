
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

/*
    获取当前程序运行路径Linux
    int bytes = MIN(readlink("/proc/self/exe", pBuf, len), len - 1);
    if(bytes >= 0)
    pBuf[bytes] = '\0';
*/

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    using std::ifstream;
    using std::ofstream;

    using std::istringstream;
    using std::ostringstream;
    using std::string;

    string filepath = "test.md";
    ifstream fin(filepath);
    ifstream fout;

    string input, output, output2, output3;
    // cout << "请输入一些东西：" << endl;
    // cin >> input >> output >> output2 >> output3;

    istringstream sin;
    ostringstream sout;

    int cnt = 0;
    while (cnt < 3) {
        sout << "hello" << cnt << endl;
        ++cnt;
    }
    cout << "sout ends :" << endl << sout.str() << endl;

    cout << "将sout的str存入sin中" << endl;
    // istringstream sin(sout.str());
    sin.str(sout.str());

    if (!sin) {
        cout << "string failed to read.\n";
        exit(1);
    }

    cout << "你的输入是：" << endl << sin.str() << endl;

    if (fin.fail()) {
        cout << "File failed to open.\n";
        exit(1);
    }

    if (fin.good()) {
        cout << fin.rdbuf();
    }

    // << "\n\nEnd."
    cout << endl;
    return 0;
}
