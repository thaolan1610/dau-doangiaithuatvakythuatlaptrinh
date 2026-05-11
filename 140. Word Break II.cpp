class Solution {
public:
    unordered_map<int, vector<string>> memo;
    unordered_set<string> dict;

    vector<string> dfs(string &s, int start) {
        if (memo.count(start)) return memo[start];

        vector<string> res;

        if (start == s.size()) {
            res.push_back("");
            return res;
        }

        string word = "";

        for (int i = start; i < s.size(); i++) {
            word += s[i];

            if (dict.count(word)) {
                vector<string> sub = dfs(s, i + 1);

                for (string &sentence : sub) {
                    if (sentence.empty())
                        res.push_back(word);
                    else
                        res.push_back(word + " " + sentence);
                }
            }
        }

        return memo[start] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s, 0);
    }
};