class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() < 2) return nums;

        std::ranges::sort(nums);
        std::map<int, std::vector<int>> count_map;

        int current_count = 1;
        const auto size = nums.size();
        for(std::size_t i = 1; i < size; i++) {
            if (nums[i] == nums[i-1]) {
                current_count++;
                if (i+1 < size) continue;
            }
               
            auto it = count_map.find(current_count);
            if (it != count_map.end()) {
                it->second.push_back(nums[i-1]);
            } else {
                count_map[current_count] = {nums[i-1]};
            }

            current_count = 1;
            if (i + 1 == size && nums[i] != nums[i-1]) {
                auto it = count_map.find(current_count);
                if (it != count_map.end()) {
                    it->second.push_back(nums[i]);
                } else {
                    count_map[current_count] = {nums[i]};
                }
            }
        }

        vector<int> res;
        res.reserve(k);
        for (auto it = count_map.rbegin(); it != count_map.rend() && k > 0; it++) {
            const auto & vect = it->second;
            for (auto num : vect) {
                res.push_back(num);
                k--;
                if (k == 0) break;
            }
        }

        return res;
    }
};
