class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small = *min_element(nums.begin(), nums.end());
        int large = *max_element(nums.begin(), nums.end());
          int possible =0;
        for(int i =1 ; i<= small ; i++){
          
            if(small % i==0 && large % i==0){
                possible = i;
            }
               
        }
        return possible;
    }
};