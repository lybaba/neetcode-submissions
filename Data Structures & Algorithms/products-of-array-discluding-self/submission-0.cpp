class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 0);

        int left = 1;
        vector<int> left_product(nums.size(), 0);

        int right = 1;
        vector<int> right_product(nums.size(), 0);

        const auto size = nums.size();
        for (std::size_t i = 0; i < size; i++) {
            left *= nums[i];
            left_product[i] = left;

            right *= nums[size - 1 - i];
            right_product[size-1-i] = right;
        }

        if (size > 1) {
            res[0] = right_product[1];
            res[size-1] = left_product[size-2];
        }

        for (std::size_t i = 1; i < size - 1; i++) {
            res[i] = left_product[i-1] * right_product[i+1];
        }

        return res;
    }
};
