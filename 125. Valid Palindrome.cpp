class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            // bỏ ký tự không hợp lệ bên trái
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // bỏ ký tự không hợp lệ bên phải
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // so sánh không phân biệt hoa thường
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};