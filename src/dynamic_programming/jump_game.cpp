#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // distance to last zero
        int dist = -1;
        // no need to check last index
        for (int i = nums.size() - 2; i >= 0; i--) {
            // for consecutive 0's, only the first triggers a reset
            if (dist == -1 && nums[i] == 0) {
                dist = 1;
            }
            else if (dist != -1) {
                // we can jump over the last 0
                if (nums[i] > dist) {
                    dist = -1;
                }
                else {
                    dist++;
                }
            }
        }

        return dist == -1;
    }
};