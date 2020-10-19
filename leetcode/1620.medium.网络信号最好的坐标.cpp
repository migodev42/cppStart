#include <vector>
#include <cmath>


using std::vector;
using std::floor;
using std::pow;
using std::sqrt;

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        if(towers.size()==1){
            return {towers[0][0],towers[0][1]};
        } 
        int curmax = 0;
        vector<vector<int>> rs;
        for(auto cur = 0; cur<towers.size();++cur){   
            vector<int> curtower = towers[cur];
            int curposx = curtower[0];
            int curposy = curtower[1];
            int signalsum=0;
            for(auto cmpr = 0; cmpr<towers.size();++cmpr){
                vector<int> cmprtower = towers[cmpr];
                int cmprposx = cmprtower[0];
                int cmprposy = cmprtower[1];
                int cmprq = cmprtower[2];
                double distanse = sqrt(pow(cmprposx-curposx,2) + pow(cmprposy-curposy,2));
                // cout << "cur坐标：" << curposx << " "<< curposy << "距离" << distanse << "目标距离" << radius << endl;
                if(distanse>radius) continue;
                    
                auto signal = floor(cmprq/(1+distanse));
                signalsum += signal;
                // cout << "信号" << signal << endl;
                                
            }         
            if(signalsum>curmax){
                curmax = signalsum;
                rs.clear();
                rs.push_back({curposx,curposy});
            }else if(signalsum==curmax){
                rs.push_back({curposx,curposy});
            }
            // cout << signalsum << "sum坐标：" << curposx << " "<< curposy << endl;
        }
        auto rsmin=rs[0];
        for(auto item : rs){
            // cout << item[0] << " " <<item[1] << endl;
        }
        for(auto i=1;i<rs.size();++i){
            if(rsmin[0]<rs[i][0]){
                continue;
            }else if(rsmin[0]==rs[i][0]){
                if(rsmin[1] > rs[i][1]){
                    rsmin = {rs[i][0], rs[i][1]};
                }                
            }else{
                rsmin = {rs[i][0], rs[i][1]};
            }
        }
        return rsmin;
    }
};