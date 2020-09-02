#include <iostream>
#include <sstream>
#include <string>


int main() {
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;
    using std::istringstream;
    using std::ostringstream;

    istringstream input;
    ostringstream output;
    string s;
    string result;

    cin >> result;
    while (cin >> s) {
        cout << "Your Input:" << s << endl;
        result += "," + s;
    }

    cout << "Result: " << result;
    return 0;
}
