class Solution {
public:
    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList) {

        unordered_set<string> dict(
            wordList.begin(),
            wordList.end()
        );

        // endWord không tồn tại
        if (!dict.count(endWord)) {
            return 0;
        }

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        // visited
        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {

            auto [word, steps] = q.front();
            q.pop();

            // tới đích
            if (word == endWord) {
                return steps;
            }

            string original = word;

            // đổi từng ký tự
            for (int i = 0; i < word.size(); i++) {

                char old = word[i];

                for (char c = 'a'; c <= 'z'; c++) {

                    word[i] = c;

                    // hợp lệ và chưa thăm
                    if (dict.count(word) &&
                        !visited.count(word)) {

                        visited.insert(word);

                        q.push({word, steps + 1});
                    }
                }

                word[i] = old;
            }
        }

        return 0;
    }
};