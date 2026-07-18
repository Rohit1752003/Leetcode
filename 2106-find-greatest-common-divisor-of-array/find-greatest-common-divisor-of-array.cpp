class Solution {
public:
    int findGCD(vector<int>& nums) {
        //  1st approach Brute force
        int small = *min_element(nums.begin(), nums.end());
        int large = *max_element(nums.begin(), nums.end());
        /*  int possible =0;
        for(int i =1 ; i<= small ; i++){
          
            if(small % i==0 && large % i==0){
                possible = i;
            }
               
        }
        return possible;
*/
        // 2nd Approach optimize one Using gcd() function
        return __gcd(small, large);
    }
};