#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ostream>
#include <iterator> 

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::copy;
using std::ostream_iterator;

int main(){
    vector<int> vec = {1 ,2 ,3, 4, 5};
    ostream_iterator<int> out_iter(cout, " ");
    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;
    return 0;
}
