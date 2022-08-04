#include <vector>
#include <iostream>

using namespace std;

// must run in O(n) time without division
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> output(n, 1);

    // result of multiplication of all numbers to the left
    for (int i = 1; i < n; i++) {
        output[i] = output[i - 1] * nums[i - 1];
    }

    int right_prod = 1;
    for (int i = n - 1; i >= 0; i--) {
        output[i] *= right_prod;
        right_prod *= nums[i];
    }
    
    return output;
}

int main() {
    return 0;
}