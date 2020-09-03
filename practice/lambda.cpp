#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

using std::find_if;
using std::sort;

int main() {
    vector<string> words = { "ab","abcd","abcde","abc","a" };
    int sz = 2;

    sort(words.begin(), words.end());
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a) {
        return a.size() > sz;
        });

    auto count = words.end() - wc;
    cout << count << endl;
    return 0;
}
