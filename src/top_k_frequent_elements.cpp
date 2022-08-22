#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (auto num : nums) {
        map[num]++;
    }

    vector<vector<int>> bucket (nums.size());
    for (auto& p : map) {
        bucket[p.second - 1].push_back(p.first);
    }

    vector<int> res;
    for (auto it = bucket.rbegin(); res.size() < k && it != bucket.rend(); it++) {
        res.insert(res.end(), (*it).begin(), (*it).end());
    }

    return res;
}

/**
 * This version has n log(n) runtime.
 */
vector<int> topKFrequentA(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (auto num : nums) {
        map[num]++;
    }
    auto cmp = [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second < rhs.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> priority(map.begin(), map.end(), cmp);

    vector<int> res;

    for (int i = 0; i < k; i++) {
        res.push_back(priority.top().first);
        priority.pop();
    }

    return res;
}