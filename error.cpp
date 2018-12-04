//391
class Solution {
public:
    bool helper(vector<int> rect1, vector<int> rect2){
        if((rect1[0]>rect2[0] && rect1[0]<rect2[2]) &&(rect1[1]>rect2[1] && rect1[1]<rect2[3])){
            return true;
        }
        if((rect1[0]>rect2[0] && rect1[0]<rect2[2]) &&(rect1[3]>rect2[1] && rect1[3]<rect2[3])){
            return true;
        }
        if((rect1[2]>rect2[0] && rect1[2]<rect2[2]) &&(rect1[1]>rect2[1] && rect1[1]<rect2[3])){
            return true;
        }
        if((rect1[2]>rect2[0] && rect1[2]<rect2[2]) &&(rect1[3]>rect2[1] && rect1[3]<rect2[3])){
            return true;
        }

        if((rect2[0]>rect1[0] && rect2[0]<rect1[2]) &&(rect2[1]>rect1[1] && rect2[1]<rect1[3])){
            return true;
        }
        if((rect2[0]>rect1[0] && rect2[0]<rect1[2]) &&(rect2[3]>rect1[1] && rect2[3]<rect1[3])){
            return true;
        }
        if((rect2[2]>rect1[0] && rect2[2]<rect1[2]) &&(rect2[1]>rect1[1] && rect2[1]<rect1[3])){
            return true;
        }
        if((rect2[2]>rect1[0] && rect2[2]<rect1[2]) &&(rect2[3]>rect1[1] && rect2[3]<rect1[3])){
            return true;
        }

        return false;
    }

    bool isRectangleCover(vector<vector<int>>& rectangles) {
        pair<int, int> ld(INT_MAX, INT_MAX), ru(INT_MIN, INT_MIN);
        for(auto x:rectangles){
            if(x[0]<ld.first) ld.first=x[0];
            if(x[1]<ld.second) ld.second=x[1];
            if(x[2]>ru.first) ru.first=x[2];
            if(x[3]>ru.second) ru.second=x[3];
        }
        int acreage=(ru.second-ld.second)*(ru.first-ld.first);
        //vector<vector<int>> rect(ru.first-ld.first, vector<int>(ru.second-ld.second,0));

        for(int i=0; i<rectangles.size(); i++){
            for(int j=i+1; j<rectangles.size(); j++){
                if(helper(rectangles[i],rectangles[j])) return false;
            }
        }

        for(auto x:rectangles){
            for(int i=x[0]-ld.first; i<x[2]-ld.first; i++){
                for(int j=x[1]-ld.second; j<x[3]-ld.second; j++){
                    //if(rect[i][j]!=0) return false;
                    //rect[i][j]=1;
                    acreage--;
                }
            }
        }

        if(acreage!=0) return false;
        return true;
    }
};
