class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
          unordered_set<int> pairXor;
        unordered_set<int> ans;

        int n = nums.size();

        // All XORs of pairs (i <= j)
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        // Combine each pair XOR with every element
        for (int x : pairXor) {
            for (int num : nums) {
                ans.insert(x ^ num);
            }
        }

        return ans.size();
    }
};