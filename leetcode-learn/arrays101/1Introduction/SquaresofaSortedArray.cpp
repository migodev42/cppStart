#include <vector>
#include <cmath>

using std::vector;
using std::pow;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        if (!A.size()) return A;
        if (A.size()==1) {
            A[0] = pow(A[0], 2);
            return A;
        }
        int curr = 0;
        while (curr < A.size()) {
            if (A[curr] >= 0) break;
            ++curr;
        }
        int left = curr-1, right = curr;
        vector<int> rs;
        while (left >= 0 && right < A.size()) {
            int leftVal = pow(A[left], 2);
            int rightVal = pow(A[right], 2);
            if (leftVal <= rightVal) {
                rs.push_back(leftVal);
                --left;
            }
            else {
                rs.push_back(rightVal);
                ++right;
            }
        }

        while (left >= 0) {
            rs.push_back(pow(A[left], 2));
            --left;
        }

        while (right < A.size()) {
            rs.push_back(pow(A[right++], 2));
        }
        return rs;
    }
};