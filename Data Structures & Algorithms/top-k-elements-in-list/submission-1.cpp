class Solution {
public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count_map;
        for (auto num : nums) {
            auto it = count_map.find(num);
            int current_count = 1;
            if (it == count_map.end()) {
                count_map[num] = current_count;
            }
            else {
                it->second++;
                current_count = it->second;
            }
        }

        auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) -> bool {
            return a.second < b.second;
        };

        std::priority_queue<std::pair<int, int>,
                             std::vector<std::pair<int, int>>,
                             decltype(cmp)> pq(cmp);
        
        for (auto [i, j] : count_map) {
            pq.push({i, j});
        }
        
        vector<int> res;
        res.reserve(k);
        while (k > 0 && !pq.empty()) {
            auto t = pq.top();
            res.push_back(t.first);
            pq.pop();
            k--;
        }

               
        return res;
    }
};
