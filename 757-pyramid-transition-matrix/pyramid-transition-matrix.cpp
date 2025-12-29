class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool dfs(string cur) {
        // If already computed, return stored result
        if (memo.count(cur)) return memo[cur];

        // Top reached
        if (cur.size() == 1) return memo[cur] = true;

        function<bool(int, string)> build = [&](int i, string next) {
            if (i == cur.size() - 1)
                return dfs(next);

            string key = cur.substr(i, 2);

            if (!mp.count(key)) return false;

            for (char c : mp[key]) {
                if (build(i + 1, next + c))
                    return true;
            }
            return false;
        };

        return memo[cur] = build(0, "");
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // Build mapping
        for (string &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }

        return dfs(bottom);
    }
};
