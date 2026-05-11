class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;   // cộng xong là xong luôn
                return digits;
            }
            digits[i] = 0; // nếu = 9 thì thành 0 và nhớ carry
        }

        // nếu toàn là 9 (vd: 999)
        digits.insert(digits.begin(), 1);
        return digits;
    }
};