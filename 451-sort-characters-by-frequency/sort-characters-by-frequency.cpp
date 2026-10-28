class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> mp;     // FIXED
        for (char c : s) mp[c]++;        // count freq

        sort(s.begin(), s.end(), [&](char a, char b){   // FIXED
            if (mp[a] != mp[b])
                return mp[a] > mp[b];   // higher freq first
            return a < b;               // tie → alphabetical
        });  // FIXED

        return s;
    }
};
