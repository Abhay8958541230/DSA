class Solution {
public:
    struct Node {
        long long wt;
        vector<int> idx;
    };

    static bool lexSmaller(const vector<int>& a, const vector<int>& b) {
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
    }

    static Node better(const Node &a, const Node &b) {
        if (a.wt != b.wt) return (a.wt > b.wt) ? a : b;
        return lexSmaller(a.idx, b.idx) ? a : b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        struct Item {
            int l, r, w, id;
        };

        vector<Item> arr;
        arr.reserve(n);
        for (int i = 0; i < n; i++)
            arr.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});

        sort(arr.begin(), arr.end(), [](const Item &a, const Item &b) {
            if (a.l != b.l) return a.l < b.l;
            return a.r < b.r;
        });

        vector<int> starts(n);
        for (int i = 0; i < n; i++) starts[i] = arr[i].l;

        vector<int> nxt(n);
        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(starts.begin(), starts.end(), arr[i].r) - starts.begin();
        }

        vector<vector<Node>> dp(n + 1, vector<Node>(5));
        for (int k = 0; k <= 4; k++) {
            dp[n][k].wt = 0;
            dp[n][k].idx.clear();
        }

        for (int i = n - 1; i >= 0; i--) {
            dp[i][0] = dp[i + 1][0];
            for (int k = 1; k <= 4; k++) {
                Node skip = dp[i + 1][k];

                Node take;
                take.wt = arr[i].w + dp[nxt[i]][k - 1].wt;
                take.idx = dp[nxt[i]][k - 1].idx;
                take.idx.insert(lower_bound(take.idx.begin(), take.idx.end(), arr[i].id), arr[i].id);

                dp[i][k] = better(skip, take);
            }
        }

        return dp[0][4].idx;
    }
};