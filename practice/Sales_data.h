#ifndef SALSE_DATA_H
#define SALSE_DATA_H
#include <string>
struct Sales_data {
    std::string bookNo;
    unsigned unitSold = 0;
    double revenue = 0.0;
};
#endif
