class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a) pq.push({a, 'a'});
        if(b) pq.push({b, 'b'});
        if(c) pq.push({c, 'c'});

        string s;
        while (!pq.empty()){
            auto [n, ch] = pq.top();
            pq.pop();
            int len = s.size();
            if(len >= 2 && s[len-1] == ch && s[len-2] == ch){
                if(pq.empty()) break;
                auto[m, other] = pq.top();
                pq.pop();
                s += other;
                if(--m) pq.push({m, other});
                pq.push({n, ch});
            } else {
                s+= ch;
                if(--n) pq.push({n, ch});
            }
        }
        return s;
    }
};