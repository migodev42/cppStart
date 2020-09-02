#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>

int main() {
    using std::cout;
    using std::cin;
    using std::endl;
    using std::vector;
    using std::string;
    using std::accumulate;
    using std::literals::string_literals::operator""s;

    int target = 42;
    vector<int> v = { 1,52,43,78,42,31,24,36 };
    vector<string> sv = { "hello","cpp","nice!" };

    // auto result = find(v.begin(), v.end(), target);
    // cout << "The result is " << (result == v.end() ? "false" : "true") << endl;
    // cout << result - v.begin() << endl;
    // cout << v[result - v.begin()] << endl;
    string rs = accumulate(sv.begin(), sv.end(), ""s );
    cout << rs;

    return 0;
}
