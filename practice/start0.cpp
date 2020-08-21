#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <chrono>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stringstream;

/* vector<int> runningSum(vector<int> &nums) {
    int curSum = 0;
    vector<int> rs;
    for (int &item : nums) {
        cout << item;
        curSum += item;
        // item = curSum;
        rs.push_back(curSum);
    }
    return rs;
} */

class Timer {
private:
    typedef std::chrono::system_clock time_type;
    using duration_type = std::chrono::duration<double>;
    auto startTime = std::chrono::system_clock::now();
    auto endTime = std::chrono::system_clock::now();
    auto& now(std::chrono::steady_clock& t) {
        t = std::chrono::steady_clock::now();
        return t;
    }
public:
    auto start();
    auto end();
    auto duration();
};

std::chrono::steady_clock Timer::start() {
    // return now(startTime);
    startTime = std::chrono::system_clock::now();
    return startTime;
};
std::chrono::steady_clock Timer::end() {
    return now(endTime);
    endTime = std::chrono::system_clock::now();
    return endTime;
};
auto Timer::duration() {
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    return dur.count();
};

vector<int> runningSum(vector<int>& nums) {
    vector<int> rs(nums.size());
    rs[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        rs[i] = rs[i - 1] + nums[i];
    }
    return rs;
}


vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int max = candies[0];
    for (vector<int>::size_type i = 1; i < candies.size(); ++i) {
        if (candies[i] > max) {
            max = candies[i];
        }
    }
    vector<bool> rs(candies.size());
    for (vector<int>::size_type i = 0; i < candies.size(); ++i) {
        if ((max - candies[i]) <= extraCandies) {
            rs[i] = true;
        }
        else {
            rs[i] = false;
        }
    }
    return rs;
}

int reverse(int x) {
    int flag = false;
    int rs = 0;

    if (x >= INT32_MAX || x <= INT32_MIN) {
        cout << "溢出" << endl;
        return rs;
    }

    if (x < 0) {
        flag = true;
        x = -x;
    }
    // stringstream ss;
    // ss << x;
    // int pos = ss.str().size() - 1;

    string str = std::to_string(x);
    int pos = str.size() - 1;

    cout << "size:" << pos << endl;

    while (x > 0) {
        cout << "cur:" << x % 10 << endl;
        if (rs + (x % 10) * pow(10, pos) >= INT32_MAX) {
            cout << "溢出" << INT32_MAX << endl;
            return 0;
        }
        rs += (x % 10) * pow(10, pos);
        --pos;
        x = x / 10;
    }
    return flag ? -rs : rs;
}

int main() {
    using namespace std;
    vector<int> v = { 1, 2, 3, 4 };
    // vector<int> rs = runningSum(v);

    /* Timer t;
    t.start(); */

    auto start = std::chrono::system_clock::now();

    // vector<int> candies = { 2,3,5,1,3 };
    // int extraCandies = 3;
    // vector<bool> rs = kidsWithCandies(candies, extraCandies);


    int rint = -214;
    int rs = reverse(rint);

    cout << rs << endl;
    /* for (int item : rs) {
        cout << item;
    } */
    int i = 0;
    while (i < pow(10, 5)) {
        i++;
    }

    cout << "Hello Wolrd\n";
    // t.end();
    // cout << t.duration() << endl;

    /* measured work */
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    printf("Time = %lld ms\n", static_cast<long long int>(elapsed.count()));
    return 0;
}
