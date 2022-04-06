#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string s, string del = " ") {
  vector<string> result;
  int start = 0;
  int end = s.find(del);
  while (end != -1) {
    result.push_back(s.substr(start, end - start));
    // cout << s.substr(start, end - start) << endl;
    start = end + del.size();
    end = s.find(del, start);
  }
  result.push_back(s.substr(start, end - start));
  // cout << s.substr(start, end - start);
  return result;
}

int main(int argc, char const *argv[]) {
  // Takes C++ string with any separator
  string a = "Hi$%do$%you$%do$%!";
  vector<string> rs = split(a, "$%");
  for (auto r : rs) {
    cout << r << " ";
  }
  cout << endl;

  return 0;
}