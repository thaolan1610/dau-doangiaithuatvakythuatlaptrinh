class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};

        for (int i = 0; i < n; i++) {
            int add = 1 << i;

            // thêm phần đảo ngược
            for (int j = res.size() - 1; j >= 0; j--) {
                res.push_back(res[j] + add);
            }
        }

        return res;
    }
};