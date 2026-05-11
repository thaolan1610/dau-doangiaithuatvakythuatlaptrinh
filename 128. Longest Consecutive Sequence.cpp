class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> s(
            nums.begin(),
            nums.end()
        );

        int longest = 0;

        for (int num : nums) {

            // chỉ bắt đầu nếu là đầu dãy
            if (!s.count(num - 1)) {

                int currentNum = num;
                int length = 1;

                // đếm liên tiếp
                while (s.count(currentNum + 1)) {

                    currentNum++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};