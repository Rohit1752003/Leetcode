class Solution {
   
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();

    
        sort(players.begin() , players.end() ,greater<int>());
         sort(trainers.begin() , trainers.end() , greater<int>());
        int cnt = 0;

        int i  =0 , j =0 ;
        while( i < n && j < m){
              if ( trainers[j] >= players[i]) {
                    cnt++;
                    i++ , j++;
                }
                // else if (trainers[j] <  players[i]) j++;
                else i++;
        }
        
        return cnt;
    }
};