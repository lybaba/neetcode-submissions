class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;
        for (auto n : nums) {
            auto it = seen.find(n);
            if (it != seen.end()) return true;

            seen.insert(n);
        }
        return false;
    }
};