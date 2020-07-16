/* 
    把0到15之间的十进制数字转换成对应的十六进制数字
 */
#include <iostream>
#include <string>

int main(){
    using std::string;
    using std::cout;
    using std::cin;
    using std::endl;

    const string hexDigits = "0123456789ABCDEF";     // 可能的十六进制数字(0-15)

    cout << "Enter a series of numbers between 0 and 15"
         << " seperated by space. Hit ENTER when finished:"
         << endl;

    string hexRes;                                  // 用于保存转换的十六进制结果
    string::size_type n;                            // 用于保存从输出流读取的数

    while(cin >> n){
        if(n<hexDigits.size()){
            hexRes += hexDigits[n];
        }
    }

    cout << "Your hex number is:" << hexRes << endl;
    return 0;
}
