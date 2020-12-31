#include <climits>
// LONG_MIN、INT_MIN...
// https://docs.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=msvc-160
#include <vector>


using std::vector;

class Solution {
public:
    long m1=LONG_MIN;
    long m2=LONG_MIN;
    long m3=LONG_MIN;
    void compare(int target){
        if(target ==m1 ||target==m2 || target ==m3) return;
        if(target>m1){
            m3 = m2;
            m2 = m1;
            m1 = target;
        }else if(target>m2){
            m3 = m2;
            m2 = target;
        }else if(target>m3){
            m3 = target;
        }
    }
    int thirdMax(vector<int>& nums) {        
        for(int i = 0 ; i< nums.size(); ++i){
            compare(nums[i]);
        }
        return m3==LONG_MIN?m1:m3;
    }
};