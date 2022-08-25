#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // key: any character
        // value: the last index at which the character is seen
        unordered_map<char, int> m;
        int cur_len = 0, lo = -1;
        
        for (int i = 0; i < s.size(); i++) {
            auto it = m.find(s[i]);
            if (it != m.end() && (*it).second > lo) {
                lo = (*it).second;
            }
            m[s[i]] = i;
            cur_len = max(i - lo, cur_len);
        }
        
        return cur_len;
    }
    
    /* Sliding window */
    int lengthOfLongestSubstringA(string s) {
        int lo = 0, hi = 0;
        int cur_len = 0;

        unordered_set<char> check;

        for (; hi < s.size(); hi++) {
            // if the substring contains the character already
            if (check.find(s[hi]) != check.end()) {
                while (s[lo] != s[hi]) {
                    check.erase(s[lo]);
                    lo++;
                }
                if (lo != hi) {
                    lo++;
                }
            }
            else {
                check.insert(s[hi]);
                if (hi - lo + 1 > cur_len) {
                    cur_len = hi - lo + 1;
                }
            }
        }

        return cur_len;
    }
};