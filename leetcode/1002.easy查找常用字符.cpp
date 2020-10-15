// 输入：["bella","label","roller"]
// 输出：["e","l","l"]

// b:1 e:1 l:2 a:1
// l:2 a:1 b:1 e:1 
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using std::vector;
using std::string;
using std::map;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        map<char, int> charcnt;
        map<char, int> currcnt;

        for (char& c : A[0]) {
            ++charcnt[c];
        }


        for (decltype(A.size()) i = 1; i < A.size(); ++i) {
            for (char& c : A[i]) {
                ++currcnt[c];
            }
            for (auto c = charcnt.begin(); c != charcnt.end(); ++c) {
                auto charkey = c->first;
                c->second = min(c->second, currcnt[c->first]);
            }

            currcnt.clear();
        }

        vector<string> rs;
        for (auto c = charcnt.begin(); c != charcnt.end(); ++c) {
            while (c->second--) {
                rs.push_back(string(1,c->first));                
            }
        }
        return rs;
    }
};