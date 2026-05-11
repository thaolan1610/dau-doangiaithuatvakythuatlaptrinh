#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact = 1;

        for (int i = 1; i < n; i++) {
            fact *= i;
        }

        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        k--;  // đổi sang 0-index
        string ans = "";

        while (n > 0) {
            int idx = k / fact;
            ans += to_string(nums[idx]);

            nums.erase(nums.begin() + idx);

            k %= fact;
            n--;

            if (n > 0) {
                fact /= n;
            }
        }

        return ans;
    }
};