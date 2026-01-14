class Solution {
public:
    struct Event {
        long long y;
        int type;     // +1 = add, -1 = remove
        int l, r;     // compressed x-interval
        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

    struct SegTree {
        int n;
        vector<int> cover;
        vector<long long> len;
        vector<long long> xs;

        SegTree(int n, vector<long long>& xs) : n(n), xs(xs) {
            cover.assign(4 * n, 0);
            len.assign(4 * n, 0);
        }

        void pull(int node, int l, int r) {
            if (cover[node] > 0) {
                len[node] = xs[r] - xs[l];
            } else if (l + 1 == r) {
                len[node] = 0;
            } else {
                len[node] = len[node * 2] + len[node * 2 + 1];
            }
        }

        void update(int node, int l, int r, int ql, int qr, int val) {
            if (qr <= l || r <= ql) return;
            if (ql <= l && r <= qr) {
                cover[node] += val;
                pull(node, l, r);
                return;
            }
            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr, val);
            update(node * 2 + 1, mid, r, ql, qr, val);
            pull(node, l, r);
        }

        long long query() {
            return len[1];
        }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<long long> xs;
        vector<Event> events;

        // Collect x-coordinates
        for (auto& s : squares) {
            xs.push_back(s[0]);
            xs.push_back(s[0] + s[2]);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        // Build sweep events
        for (auto& s : squares) {
            long long x1 = s[0];
            long long x2 = s[0] + s[2];
            long long y1 = s[1];
            long long y2 = s[1] + s[2];

            int l = lower_bound(xs.begin(), xs.end(), x1) - xs.begin();
            int r = lower_bound(xs.begin(), xs.end(), x2) - xs.begin();

            events.push_back({y1, +1, l, r});
            events.push_back({y2, -1, l, r});
        }

        sort(events.begin(), events.end());

        SegTree st(xs.size() - 1, xs);

        // First sweep: total union area
        long long totalArea = 0;
        long long prevY = events[0].y;

        for (auto& e : events) {
            long long dy = e.y - prevY;
            totalArea += dy * st.query();
            st.update(1, 0, xs.size() - 1, e.l, e.r, e.type);
            prevY = e.y;
        }

        double half = totalArea / 2.0;

        // Second sweep: find minimal y
        st = SegTree(xs.size() - 1, xs);
        long long currArea = 0;
        prevY = events[0].y;

        for (auto& e : events) {
            long long dy = e.y - prevY;
            long long width = st.query();

            if (width > 0 && currArea + dy * width >= half) {
                return prevY + (half - currArea) / (double)width;
            }

            currArea += dy * width;
            st.update(1, 0, xs.size() - 1, e.l, e.r, e.type);
            prevY = e.y;
        }

        return prevY;
    }
};
