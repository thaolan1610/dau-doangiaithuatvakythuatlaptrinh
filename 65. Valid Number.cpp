class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;

        // bỏ khoảng trắng đầu
        while (i < n && s[i] == ' ') i++;

        // bỏ khoảng trắng cuối
        int j = n - 1;
        while (j >= 0 && s[j] == ' ') j--;

        if (i > j) return false;

        bool seenDigit = false;
        bool seenDot = false;
        bool seenE = false;
        bool digitAfterE = true;

        for (int k = i; k <= j; k++) {
            char c = s[k];

            if (isdigit(c)) {
                seenDigit = true;
                if (seenE) digitAfterE = true;
            }
            else if (c == '+' || c == '-') {
                // chỉ hợp lệ đầu chuỗi hoặc sau e/E
                if (k != i && s[k - 1] != 'e' && s[k - 1] != 'E')
                    return false;
            }
            else if (c == '.') {
                // . không được xuất hiện 2 lần và không sau e
                if (seenDot || seenE) return false;
                seenDot = true;
            }
            else if (c == 'e' || c == 'E') {
                // e chỉ xuất hiện 1 lần, phải có số trước đó
                if (seenE || !seenDigit) return false;
                seenE = true;
                digitAfterE = false; // bắt buộc có số sau e
            }
            else {
                return false;
            }
        }

        return seenDigit && digitAfterE;
    }
};