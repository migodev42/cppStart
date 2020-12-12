#include <vector>

using std::vector;

// class Solution {
// public:
//     vector<int> replaceElements(vector<int>& arr) {
//         for(int i = 0; i< arr.size(); ++i){
//             for(int j = i; j<arr.size(); ++j){
//                 if(arr[i]<arr[j]) arr[i]=arr[j];
//             }
//         }
        
//         int i =1;
//         while(i<arr.size()){
//             arr[i-1]= arr[i];
//             ++i;
//         }
//         arr[arr.size()-1]=-1;
//         return arr;
//     }
// };


class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxval = -1;
        for(int i = arr.size()-1; i>=0; --i){
            int tmp = arr[i];
            arr[i]=maxval;
            maxval = max(tmp,maxval);
        }
        return arr;
    }
};