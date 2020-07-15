#include <iostream>
#include <string>
#include <cctype>

int main() {
    using std::cout;
    using std::endl;
    using std::string;
    using std::ispunct;

    string s = ",'Hello World!!!";
    decltype(s.size()) puncCount = 0;

    for (auto c : s) {
        if (ispunct(c)) {
            puncCount++;
        }
    }
    cout << puncCount << " punc in" << s << endl;
    return 0;
}
