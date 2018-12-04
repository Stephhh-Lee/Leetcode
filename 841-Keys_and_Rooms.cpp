class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> broom(rooms.size(), false);
        broom[0] = true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            vector<int> v = rooms[q.front()];
            for(auto x:v){
                if(!broom[x]){
                    broom[x] = true;
                    q.push(x);
                }
            }
            q.pop();
        }
        for(auto x:broom){
            if(!x) return false;
        }
        return true;
    }
};
