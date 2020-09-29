#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    int* p = new int[3]{ 1, 2, 3 };
    string* p2 = new string[10]{ "a","an","the", string(3,'x')};
    return 0;
}
