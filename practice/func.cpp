#include <iostream>

int funcName(int a, int &b) { return a + (b++); }

size_t callCount() {
    static size_t cnt = 0;
    return ++cnt;
}

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    int b = 2;
    int rs = funcName(1, b);

    cout << rs << " " << b << endl;

    callCount();
    callCount();
    size_t cnt = callCount();
    cout << "cnt:" << cnt << endl;
    return 0;
}
