#include <iostream>
#include <stdexcept>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::runtime_error;

    try {
        throw runtime_error("runtime error!");
    } catch (runtime_error &err) {
        cout << err.what() << endl << "catched a err" << endl;
    }
    return 0;
}
