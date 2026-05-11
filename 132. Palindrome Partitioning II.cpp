class Solution {
public:
    int minCut(string s) {

        int n = s.size();

        // palindrome table
        vector<vector<bool>> pal(
            n,
            vector<bool>(n, false)
        );

        // dp[i] = min cut cho s[0..i]
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {

            dp[i] = i; // worst case

            for (int j = 0; j <= i; j++) {

                // palindrome
                if (s[i] == s[j] &&
                    (i - j <= 2 ||
                     pal[j + 1][i - 1])) {

                    pal[j][i] = true;

                    // cả đoạn là palindrome
                    if (j == 0) {

                        dp[i] = 0;
                    }
                    else {

                        dp[i] = min(
                            dp[i],
                            dp[j - 1] + 1
                        );
                    }
                }
            }
        }

        return dp[n - 1];
    }
};