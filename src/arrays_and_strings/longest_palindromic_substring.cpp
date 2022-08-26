#include <string>

using namespace std;

class Solution {
public:
    /**
     * This method involves skipping any number of characters to the right
     * which are identical to s[i]. This way, we account for both even-sized
     * and odd-sized palindromes. Alternatively, we can do 2n - 1 checks
     * expanding from centre.
     */
    string longestPalindrome(string s) {
        int start = 0, len = 0;

        for (int i = 0; i < s.size(); i++) {
            int lo = i - 1, hi = i;
            while (hi < s.size() && s[hi] == s[i]) hi++;
            while (lo >= 0 && hi < s.size() && s[hi] == s[lo]) hi++, lo--;
            int cur_len = hi - lo - 1;
            if (cur_len > len) {
                len = cur_len;
                start = lo + 1;
            }
        }

        return s.substr(start, len);
    }
};