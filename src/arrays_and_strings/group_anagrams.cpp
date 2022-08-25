#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        // main idea here is, instead of using the actual vector of counting sort
        // as the key, use a sorted string
        /* all anagrams share the same sorted string */
        unordered_map<string, vector<string>> m;
        for (auto& str : strs) {
            string key{str};
            sort(begin(key), end(key));
            m[key].push_back(str);
        }

        for (auto& p : m) {
            res.push_back(move(p.second));
        }

        return res;
    }
};