#include <iostream>
#include <vector>
#include <string>

int main() {
    using std::vector;
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;

    vector<int> myVec;
    for (int i = 0; i != 100; ++i) {
        myVec.push_back(i);
    }

    vector<string> strVec;
    string tmp;
    cout << "请输入一些需要存放的文字，以空格分隔，ctrl+D结束"<< endl;
    while(cin >> tmp){
        strVec.push_back(tmp);
    }

    // cout << myVec << endl;
    return 0;
}
