#include <vector>

using std::vector;


class Solution {
public:
   void duplicateZeros(vector<int>& arr) {
        int i = 0;
        while (i < arr.size()) {
            if (arr[i] == 0) {
                // arr.resize(arr.size() + 1);
                for (int move = arr.size()-1; move > i; --move) {
                    arr[move] = arr[move - 1];
                }
                i += 2;
            }
            else {
                ++i;
            }
        }
    }
};