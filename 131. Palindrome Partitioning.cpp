class Solution {
public:

    vector<vector<string>> ans;
    vector<string> path;

    // kiểm tra palindrome
    bool isPalindrome(string& s, int left, int right) {

        while (left < right) {

            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    void backtrack(string& s, int start) {

        // hết chuỗi
        if (start == s.size()) {

            ans.push_back(path);
            return;
        }

        // thử mọi substring
        for (int end = start;
             end < s.size();
             end++) {

            // nếu palindrome
            if (isPalindrome(s, start, end)) {

                // cắt substring
                path.push_back(
                    s.substr(start,
                             end - start + 1)
                );

                // DFS tiếp
                backtrack(s, end + 1);

                // backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        backtrack(s, 0);

        return ans;
    }
};