#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


/*  
    获取当前程序运行路径Linux
    int bytes = MIN(readlink("/proc/self/exe", pBuf, len), len - 1);
    if(bytes >= 0)
    pBuf[bytes] = '\0'; 
*/

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    using std::ifstream;
    using std::ofstream;

    using std::istringstream;
    using std::ostringstream;
    using std::string;

    ifstream fin("README.md");
    ifstream fout;

    // istringstream sin;
    // ostringstream sout;
    
    // fin.open("README.md");
    
    if(fin.fail())
    {
        cout << "File failed to open.\n";
        exit(1);
    }

    if(fin.good()){
        cout << fin.rdbuf();
    }

    cout << "End." << endl;
    return 0;
}
