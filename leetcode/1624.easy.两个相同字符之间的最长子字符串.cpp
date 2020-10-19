#include <algorithm>
#include <map>

using std::max;
using std::map;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char, int> charmap;
        int size=-1, maxsize = 0;
        
        for(auto i = 0; i<s.size(); ++i){
            char curchar = s[i];
            if(charmap.find(curchar) == charmap.end()){
              charmap[curchar] = i;  
            } 
            else{
              size = i-charmap[curchar]-1;  
              maxsize = max(size,maxsize); 
            } 
        }
        if(size==-1) return size;
        return maxsize;
    }
};