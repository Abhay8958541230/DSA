class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) ones1.push_back({i, j});
                if (img2[i][j] == 1) ones2.push_back({i, j});
            }
        }

        unordered_map<int, int> shifts;
        int answer = 0;

        for (auto [r1, c1] : ones1) {
            for (auto [r2, c2] : ones2) {
                int rowShift = r2 - r1;
                int colShift = c2 - c1;

                // Offset by n so negative shifts can be encoded safely.
                int key = (rowShift + n) * (2 * n + 1) + (colShift + n);

                answer = max(answer, ++shifts[key]);
            }
        }

        return answer;
    }
};