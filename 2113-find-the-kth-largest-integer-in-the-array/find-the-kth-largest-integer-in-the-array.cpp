class Solution {
public:

   
 
    
    string kthLargestNumber(vector<string>& nums, int k) {

   auto cmp = [](const string& a, const string& b) {
        if (a.size() != b.size())
            return a.size() < b.size();

        return a < b;
    };

    priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);

    for (auto it : nums) {
        pq.push(it);
    }

    while (k > 1) {
        pq.pop();
        k--;
    }

    return pq.top();
}
};
