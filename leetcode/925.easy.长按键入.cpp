#include <string>

using std::string;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {                
        int i=0, j=0;
        while(i<typed.size() && j<typed.size()){
            if(i<name.size() && name[i]==typed[j]){
                ++j;
                ++i;
            }else if(j>0 && typed[j]==typed[j-1]){
                ++j;
            }else{
                return false;
            }
        }
        return i==name.size();
    }
};