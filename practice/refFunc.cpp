#include <iostream>
#include <string>

using std::string;

char &getVal(string &str, string::size_type idx) {
    return str[idx]; // getVal假定idx是有效的
}

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    string s = "hello";
    getVal(s, 0) = 'i'; // iello
    cout << s << endl;
    return 0;
}
