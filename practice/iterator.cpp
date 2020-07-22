#include <cctype>
#include <iostream>
#include <string>
#include <vector>
int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    using std::string;
    using std::vector;

    using std::isspace;
    using std::toupper;

    string s = "some string";
    cout << "origin: " << s << endl;

    if (s.begin() != s.end()) {
        auto oneChar = s.begin();
        *oneChar = toupper(*oneChar);
    }
    cout << "result: " << s << endl;

    /* 当遇到空格或者到迭代器尾部时候循环停止 */
    for (auto el = s.begin(); el != s.end() && !isspace(*el); ++el) {
        *el = toupper(*el);
    }
    cout << "result: " << s << endl;

    vector<string> text = {
        "Contrary to popular belief, Lorem Ipsum is not simply random text. It "
        "has roots in a piece of classical Latin literature from 45 BC, making "
        "it over 2000 years old. ",
        "The standard chunk of Lorem Ipsum used since the 1500s is reproduced "
        "below for those interested. "};

    /* 输出text中的每段文字 */
    cout << "输出text的第一段文字:" << endl;
    for (auto el = text.cbegin(); el != text.cend() && !el->empty(); ++el) {
        cout << *el << endl;
    }

    return 0;
}
