class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<std::string, std::size_t> ana_index_map;
        for (auto & str : strs) {
            std::string key = str;
            std::sort(key.begin(), key.end());
            auto it  = ana_index_map.find(key);
            if (it != ana_index_map.end()) {
                res[it->second].emplace_back(str);
            } else {
                res.push_back({str});
                ana_index_map[key] = res.size() - 1;
            }
        }

        return res;
    }
};
