#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

string reverseLeftWords(string s, int n) {
    return s.substr(n) + s.substr(0,n);
}
int main() {
    string s = "abcdefg";
    int n = 2;

    string rs = reverseLeftWords(s,n);
    cout << "rs: " << rs << endl;
    return 0;
}
