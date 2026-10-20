class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> ans;

        // flatten matrix into ans
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                ans.push_back(matrix[i][j]);
            }
        }

       priority_queue<int , vector<int>  , greater<int>> pq;
       for(auto it : ans)pq.push(it);

       while(k >1){
        pq.pop();
        k--;
       }
       return pq.top();

        // // k-th smallest is at index k-1
        // return ans[k - 1];
    }
};
