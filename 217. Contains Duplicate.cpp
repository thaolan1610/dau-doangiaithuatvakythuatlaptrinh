#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (int x : nums) {
            if (s.count(x)) {
                return true;
            }
            s.insert(x);
        }

        return false;
    }
};