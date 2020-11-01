class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int rs = 0;
        int curHeight = heights[0];
        for(int nxt=1; nxt< heights.size(); ++nxt){
            // cout << " heights: " << curHeight << " " << heights[nxt] << endl;
            // cout << " bricks: " << bricks << endl;
            // cout << " ladders: " << ladders << endl << endl;
            
            int nxtHeight =  heights[nxt];
            if(curHeight >= nxtHeight){
                ++rs;
                curHeight = nxtHeight;
                continue;
            } 
            
            if(bricks == 0 && ladders == 0) break;
            
            if(nxtHeight-curHeight<=bricks){
                bricks -= nxtHeight-curHeight;
            }else{
                if(ladders == 0 ){
                    break;
                }else{
                    --ladders;
                }
            }
                        
            ++rs;
            curHeight = nxtHeight;
        }
        return rs;
    }
};