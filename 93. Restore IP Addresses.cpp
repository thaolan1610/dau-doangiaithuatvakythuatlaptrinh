class Solution {
public:
    vector<string> res;

    bool valid(string s) {
        if (s.size() > 1 && s[0] == '0') return false;
        int val = stoi(s);
        return val >= 0 && val <= 255;
    }

    void backtrack(string& s, int idx, int part, string path) {
        if (part == 4 && idx == s.size()) {
            res.push_back(path);
            return;
        }

        if (part == 4 || idx == s.size()) return;

        for (int len = 1; len <= 3; len++) {
            if (idx + len > s.size()) break;

            string seg = s.substr(idx, len);

            if (valid(seg)) {
                if (part == 0)
                    backtrack(s, idx + len, part + 1, seg);
                else
                    backtrack(s, idx + len, part + 1, path + "." + seg);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return res;
    }
};