class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord ,1});
        st.erase(beginWord);
        while(!q.empty()){
            string node = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(node==endWord)return steps;
            for(int i =0 ; i < node.size();i++){
                char og = node[i];
                for(char ch = 'a ' ; ch <= 'z';ch++ ){
                    node[i]= ch;
                    if(st.find(node) != st.end()){
                        q.push({node,steps+1});
                        st.erase(node);
                        
                    }
                }
                node[i]=og;
            }
        }
return 0;

    }
};