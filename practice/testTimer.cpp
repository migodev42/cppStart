#include <iostream>
#include <cmath>
#include <chrono>
#include <string>

using std::cout;
using std::endl;

#include <chrono>
class Timer {
private:
    using time_type = std::chrono::high_resolution_clock;

    // using duration_type = std::chrono::duration<double>; // s
    using result_type = std::chrono::milliseconds;        // ms    
    void setTime(time_type::time_point& t) {
        t = time_type::now();
    }
public:
    time_type::time_point startTime;
    time_type::time_point endTime;
    auto start();
    auto end();
    auto duration();
};

using std::chrono::time_point_cast;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::time_point;
using std::chrono::high_resolution_clock;

auto Timer::start() {
    setTime(startTime);
    return duration_cast<result_type>
        (startTime.time_since_epoch()).count();
};
auto Timer::end() {
    setTime(endTime);
    return duration_cast<result_type>
        (endTime.time_since_epoch()).count();
};
auto Timer::duration() {
    return duration_cast<result_type>(endTime - startTime).count();
};


int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    Timer s;
    auto s0 = s.start();
    cout << "start: " << s0 << " milliseconds since epoch" << std::endl;

    int i = 0;
    while (i < pow(10, 7)) {
        i++;
    }
    auto s1 = s.end();
    cout << "start: " << s1 << " milliseconds since epoch" << std::endl;
    cout << "Time = " << s.duration() << "ms" << endl;

    return 0;
}
