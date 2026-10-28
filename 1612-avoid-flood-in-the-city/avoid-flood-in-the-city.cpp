class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int r = rains.size();
        vector<int> ans(r, 1);
        unordered_map<int, int> lastRain;
        set<int> dryDays;
        for(int i = 0; i < r; i++){
            if(rains[i] == 0){
                dryDays.insert(i);
            }
            else{
                int l = rains[i];
                ans[i] = -1;
                if(lastRain.count(l)){
                    auto it = dryDays.upper_bound(lastRain[l]);
                    if(it == dryDays.end()){
                        return {};
                    }
                    ans[*it] = l;
                    dryDays.erase(it);
                }
                lastRain[l] = i;
            }
        }
        return ans;
    }
};