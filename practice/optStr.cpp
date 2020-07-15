#include <iostream>
#include <string>
#include <cctype>

int main() {
    using std::cout;
    using std::endl;
    using std::string;
    using std::toupper;
    // cout << "Hello Wolrd\n";
    string s = "Hello Wolrd";
    for (auto &c : s) {
        c = toupper(c);
    }
    cout << s << endl;
    return 0;
}
