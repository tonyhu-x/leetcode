#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    // dutch partitioning problem
    int a = 0, b = 0, c = nums.size() - 1;

    // a -> red pointer
    // b -> white pointer
    // c -> blue pointer
    // invariant: b >= a
    // in this algorithm, any index before b has already been sorted (either 0
    // or 1)
    while (b <= c) {
        if (nums[b] == 0) {
            nums[b] = nums[a];
            nums[a] = 0;
            a++;
            b++;
        }
        else if (nums[b] == 1) {
            b++;
        }
        else {
            // notice here we don't advance b, because it may not be sorted still
            nums[b] = nums[c];
            nums[c] = 2;
            c--;
        }
    }

    // each step of this algorithm advances either b or c
    // therefore it's o one-pass algorithm
}
