class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        vector<int> window(128, 0);

        for (char c : t) need[c]++;

        int required = 0;
        for (int i = 0; i < 128; i++) {
            if (need[i] > 0) required++;
        }

        int l = 0, r = 0;
        int valid = 0;

        int start = 0;
        int minLen = INT_MAX;

        while (r < s.size()) {
            char c = s[r];
            r++;

            if (need[c]) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            // thu nhỏ cửa sổ
            while (valid == required) {
                if (r - l < minLen) {
                    start = l;
                    minLen = r - l;
                }

                char d = s[l];
                l++;

                if (need[d]) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};