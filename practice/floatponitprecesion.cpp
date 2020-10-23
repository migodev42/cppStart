#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::floor;

int main() {
    float a = 0.1;
    float b = 0.2;
    float c = 0.3;
    double a1 =0.1;
    double b1 =0.2;
    double c1 = 0.3;
    // bool equal = (a + b) == 0.3;    // false
    // bool equal = (a + b) == c;   // true

    bool equal = (a1 + b1) == c1;    // false
    // bool equal = (a1 + b1) == 0.3;    // false

    bool equal2 = (0.1*10 + 0.2*10)/10 == 0.3;
    bool equal3 =  35.41 * 100 == 3541;
    bool equal4 =  floor(35.41 * 100) == 3541;
    cout << equal << endl;
    cout << equal2 << endl;
    cout << equal3 << endl;
    cout << equal4 << endl;
    return 0;
}
