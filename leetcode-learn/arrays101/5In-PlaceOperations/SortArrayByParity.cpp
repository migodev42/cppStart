#include <vector>
using std::vector;

class Solution {
public:
    void swap (vector<int>& A, int pos1, int pos2){
        int tmp = A[pos2];
        A[pos2] = A[pos1];
        A[pos1] = tmp;        
    }
    vector<int> sortArrayByParity(vector<int>& A) {
        int odd =0;
        int even = A.size()-1;
        int i=0;
        while(i<A.size()){
            if(A[i]%2==0){
                swap(A,odd,i);
                ++odd;
            }else{
                // swap(A,even,i);
                // --even;
            }
            ++i;
        }
        return A;
    }
};