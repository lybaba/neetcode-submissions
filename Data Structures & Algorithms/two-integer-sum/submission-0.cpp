class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, std::size_t> memo;

        const std::int64_t size = nums.size();

        for (std::int64_t i = 0; i < size; i++) {
            auto prev_num = target - nums[i];
            auto it = memo.find(prev_num);
            if (it != memo.end()) {
                return {static_cast<int>(it->second), static_cast<int>(i)};
            }

            memo[nums[i]] = i;
        }

        return {};
    }
};
