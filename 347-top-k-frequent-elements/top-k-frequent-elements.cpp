class Solution {
public:
    // vector<int> topKFrequent(vector<int>& nums, int k) {
     /*   unordered_map<int , int> freq;
        for(int x : nums){
            freq[x]++;
        }
        vector<pair<int,int>> arr(freq.begin(), freq.end());

            sort(arr.begin(), arr.end(), [](auto &a, auto &b){
                return a.second > b.second;   // sort by count decreasing
            });
        
      
        int r= k ;
        vector<int>ans;
        int i =0 ;
        while(r>0){
                ans.push_back(arr[i].first);
                i++;
                r--;
            }

        return ans;
        */
     vector<int> topKFrequent(vector<int>& nums, int k) {
          unordered_map<int, int> freq;
       for(auto it :nums)freq[it]++;
        priority_queue<pair<int , int>> pq;
       for(auto it : freq){
        pq.push({  it.second , it.first});
       }
        vector<int> ans;
         while (k > 0 && !pq.empty()) {
            auto [cnt, val] = pq.top();
            pq.pop();

            ans.push_back(val);
            k--;
        }
       return ans;
    }
};