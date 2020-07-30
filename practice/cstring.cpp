#include <iostream>
#include <cstring>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    char ca[] = {'C', '+', '+','\0'}; // 没有以空字符结束
    cout << strlen(ca) << endl;  // 严重错误，ca没有以空字符结束
    // cout << "Hello Wolrd\n";
    return 0;
}
