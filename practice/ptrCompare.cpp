#include <iostream>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Hello Wolrd\n";
    int sz = 42, i = 10000;
    int *e = &sz, *p = &i;
    /* 未定义的：p和e无关，因此比较毫无意义 */
    if (p < e) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
