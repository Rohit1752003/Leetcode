class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<bool>ans(51 , false);
        int n = ranges.size();
        for(auto it : ranges){
            for(int i  =it[0] ; i <= it[1] ;i++ ){
                ans[i] = true;
            }
        }

        for(int i = left ; i <= right ; i++){
            if(!ans[i] )return false;
        }
        return true;
    }
};