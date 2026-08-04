class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int smallest = nums[0];
        int largest = nums[n-1];
        for(int i =smallest ; i<= largest; i++){
 
            if (!binary_search(nums.begin(), nums.end(), i))
                ans.push_back(i);
        }
        return ans;
    }
};