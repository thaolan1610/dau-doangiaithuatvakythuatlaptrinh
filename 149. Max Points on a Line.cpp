class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int res = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> mp;
            int same = 1; // trùng điểm
            int best = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    same++;
                    continue;
                }

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                string key = to_string(dx) + "/" + to_string(dy);

                mp[key]++;
                best = max(best, mp[key]);
            }

            res = max(res, best + same);
        }

        return res;
    }
};