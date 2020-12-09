#include <vector>

using std::vector;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) return false;
        
        int curr = 1;
        while(curr <arr.size()){
            if(arr[curr] < arr[curr-1]) break;
            if(arr[curr] == arr[curr-1]) return false;
            ++curr;
        }
        if(curr==arr.size() || curr==1) return false;
        ++curr;
        while(curr <arr.size()){
            if(arr[curr] >= arr[curr-1]) return false;
            ++curr;
        }
            
        return true;
    }
};