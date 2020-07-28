#include <iostream>
#include <iterator>

int main() {
    using std::begin;
    using std::cin;
    using std::cout;
    using std::end;
    using std::endl;

    cout << "Find the first < 0 element in a array..." << endl << endl;
    int arr[] = {0, 1, 2, 3, 4, -1, -2, -3, -4}; //
    int *abeg = begin(arr), *aend = end(arr);
    int pos = 0;
    while (abeg != aend && *abeg >= 0) {
        ++abeg;
        ++pos;
    }
    if (abeg != aend) {
        cout << "Value:" << *abeg << "，Pos:" << pos << endl;
    }else{
        cout << "Not Found." << endl;
    }    
    return 0;
}
