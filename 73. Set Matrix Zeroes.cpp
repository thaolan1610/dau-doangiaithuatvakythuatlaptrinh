class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool col0 = false;

        // bước 1: đánh dấu
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) col0 = true;

            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;   // đánh dấu hàng
                    matrix[0][j] = 0;   // đánh dấu cột
                }
            }
        }

        // bước 2: set zero (trừ hàng 0 và cột 0)
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }

            // xử lý cột 0
            if (col0) {
                matrix[i][0] = 0;
            }
        }
    }
};