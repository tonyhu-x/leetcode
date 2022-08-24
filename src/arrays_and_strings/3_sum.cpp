#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    // reduce this to a two-sum problem
    for (int i = 0; i < nums.size() - 2; i++) {
        int target = -nums[i];
        int lo = i + 1, hi = nums.size() - 1;

        while (lo < hi) {
            if (nums[lo] + nums[hi] == target) {
                vector<int> tmp {nums[i], nums[lo], nums[hi]};
                res.push_back(tmp);
                // here we must skip duplicates
                while (lo < hi && nums[lo + 1] == nums[lo]) {
                    lo++;
                }
                lo++;
                while (lo < hi && nums[hi - 1] == nums[hi]) {
                    hi--;
                }
                hi--;
            }
            else if (nums[lo] + nums[hi] < target) {
                lo++;
            }
            else {
                hi--;
            }
        }
        while (i < nums.size() - 1 && nums[i + 1] == nums[i]) {
            i++;
        }
    }

    return res;
}

int main() {
    vector<int> nums {-1, 0, 1, 2, -1, 4};
    threeSum(nums);
}