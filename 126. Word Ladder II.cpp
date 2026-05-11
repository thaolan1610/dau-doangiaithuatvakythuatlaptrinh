class Solution {
public:

    vector<vector<string>> ans;

    unordered_map<string, vector<string>> parents;

    void dfs(string word,
             string beginWord,
             vector<string>& path) {

        // tới beginWord
        if (word == beginWord) {

            vector<string> temp = path;
            reverse(temp.begin(), temp.end());

            ans.push_back(temp);
            return;
        }

        for (string parent : parents[word]) {

            path.push_back(parent);

            dfs(parent, beginWord, path);

            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList) {

        unordered_set<string> dict(
            wordList.begin(),
            wordList.end()
        );

        // endWord không tồn tại
        if (!dict.count(endWord)) {
            return {};
        }

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        bool found = false;

        while (!q.empty() && !found) {

            int size = q.size();

            unordered_set<string> levelVisited;

            for (int i = 0; i < size; i++) {

                string word = q.front();
                q.pop();

                string original = word;

                // thử đổi từng ký tự
                for (int j = 0; j < word.size(); j++) {

                    char old = word[j];

                    for (char c = 'a'; c <= 'z'; c++) {

                        word[j] = c;

                        // không tồn tại
                        if (!dict.count(word)) {
                            continue;
                        }

                        // chưa visited
                        if (!visited.count(word)) {

                            if (!levelVisited.count(word)) {

                                q.push(word);
                                levelVisited.insert(word);
                            }

                            parents[word].push_back(original);

                            if (word == endWord) {
                                found = true;
                            }
                        }
                    }

                    word[j] = old;
                }
            }

            // xóa sau khi hết level
            for (string w : levelVisited) {
                visited.insert(w);
            }
        }

        // không tìm thấy
        if (!found) {
            return {};
        }

        vector<string> path = {endWord};

        dfs(endWord, beginWord, path);

        return ans;
    }
};