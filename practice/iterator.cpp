#include <cctype>
#include <iostream>
#include <string>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    using std::toupper;
    using std::isspace;
    
    string s = "some string";
    cout << "origin: " << s << endl;

    if (s.begin() != s.end()) {
        auto oneChar = s.begin();
        *oneChar = toupper(*oneChar);
    }
    cout << "result: " << s << endl;

    /* 当遇到空格或者到迭代器尾部时候循环停止 */
    for (auto el = s.begin(); el !=s.end() && !isspace(*el) ; ++el) {
        *el = toupper(*el);
    }    
    cout << "result: " << s << endl;
    
    return 0;
}
