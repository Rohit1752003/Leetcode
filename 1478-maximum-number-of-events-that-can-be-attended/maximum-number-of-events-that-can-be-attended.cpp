class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
         int n = events.size();

        sort(events.begin() , events.end());
        int i = 0 ;
        int cnt = 0 ;
        int day = 0 ;
        priority_queue<int , vector<int> , greater<int>> pq;

        while( i < n  || !pq.empty()){
            if(pq.empty()){
                day = events[i][0];
            }

            while(i < n  && day >= events[i][0]){
                pq.push(events[i][1]);
                i++;
            }
            while(!pq.empty() && day > pq.top()){
                pq.pop();
            }
        if(!pq.empty()){
              pq.pop();
            day++;
            cnt++;
        }
          
        }
        
         return cnt;
      
    }
};