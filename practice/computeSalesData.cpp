#include <iostream>
#include <string>
// #include "Sales_data.h" /* 若Sales_data定以在另一个头文件Sales_data.h内 */
struct Sales_data {
    std::string bookNo;
    unsigned unit_sold = 0;
    double revenue = 0.0;
};

struct Sales_rs {
    std::string bookNo;
    unsigned totalCnt = 0;
    double totalRevenue = 0.0;
};

void getSales_data(Sales_data &d) {
    using namespace std;
    double price = 0.0;
    cin >> d.bookNo >> d.unit_sold >> price;
    d.revenue = d.unit_sold * price;
}

int computeSales_data(Sales_data &d1, Sales_data &d2, Sales_rs &rs) {
    using namespace std;
    if (d1.bookNo != d2.bookNo) {
        cout << "两笔交易的ISBN编号不一致" << endl;
        return -1;
    }
    rs.bookNo = d1.bookNo;
    rs.totalCnt = d1.unit_sold + d2.unit_sold;
    rs.totalRevenue = d1.revenue + d2.revenue;
    cout << "ISBN：" << rs.bookNo << " 总销售量:" << rs.totalCnt << " 总销售额"
         << rs.totalRevenue << endl;

    if (rs.totalCnt != 0) {
        cout << "平均价格" << rs.totalRevenue / rs.totalCnt << endl;
    } else {
        cout << "no sales" << endl;
    }

    return 0;
}

int main() {
    using namespace std;
    cout << "Start \n";
    /* 声明两个Sales_data实例 */
    Sales_data d1, d2;

    /* 读入两条数据 */
    getSales_data(d1);
    getSales_data(d2);

    /* 输出两条数据的和 */
    Sales_rs rs;
    int hasError = computeSales_data(d1, d2, rs);
    if (hasError != 0) {
        cout << "计算出错" << endl;
        return -1;
    }

    // cout << d1.revenue << " " << d2.revenue << endl;

    cout << "End \n";
    return 0;
}
