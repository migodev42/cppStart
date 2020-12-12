#include <vector>

using std::vector;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for(int i = 0; i< arr.size(); ++i){
            for(int j = i; j<arr.size(); ++j){
                if(arr[i]<arr[j]) arr[i]=arr[j];
            }
        }
        
        int i =1;
        while(i<arr.size()){
            arr[i-1]= arr[i];
            ++i;
        }
        arr[arr.size()-1]=-1;
        return arr;
    }
};