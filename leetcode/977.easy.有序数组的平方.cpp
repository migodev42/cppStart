#include
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        deque<int> left;
        deque<int> right;
        for(auto &item : A){
            if(item<0)left.push_front(pow(item,2));
            else right.push_back(pow(item,2));
        }
        vector<int> rs;

        while(left.size() && right.size()){
            auto curleft = left.front();
            auto curright = right.front();
            if(curleft<curright){
                rs.push_back(curleft);
                left.pop_front();
            }else{
                rs.push_back(curright);
                right.pop_front();
            }
        }

        while(left.size()){
            auto curleft = left.front();
            rs.push_back(curleft);
            left.pop_front();
        }

        while(right.size()){
            auto curright = right.front();
            rs.push_back(curright);
            right.pop_front();
        }
        return rs;
    }
};