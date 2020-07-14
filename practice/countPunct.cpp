#include <iostream>

int main() {
    using std::cout;
    using std::string;

    string s = ",'Hello World!!!";
    decltype(s.size()) puncCount = 0;

    for (auto c : s) {
        if (ispunct(c)) {
            puncCount++;
        }
    }
    cout << puncCount << " punc in" << s;
    return 0;
}
