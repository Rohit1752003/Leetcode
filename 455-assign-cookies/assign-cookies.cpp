class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        int n = g.size();
        int m = s.size();

    
        sort(g.begin() , g.end() ,greater<int>());
         sort(s.begin() , s.end() , greater<int>());
        int cnt = 0;

        int i  =0 , j =0 ;
        while( i < n && j < m){
              if ( s[j] >= g[i]) {
                    cnt++;
                    i++ , j++;
                }
              
                else i++;
        }
        
        return cnt;
    }
};