#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int k = 2; k <= n; k++) {
            string temp = "";

            for (int i = 0; i < s.size(); ) {
                int j = i;

                while (j < s.size() && s[j] == s[i]) {
                    j++;
                }

                temp += to_string(j - i);
                temp += s[i];

                i = j;
            }

            s = temp;
        }

        return s;
    }
};