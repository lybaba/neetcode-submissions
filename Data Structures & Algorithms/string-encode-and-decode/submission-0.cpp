class Solution {
public:

    string encode(vector<string>& strs) {
        std::string res = "";
        for (const auto & str: strs) {
            res += std::to_string(str.size());
            res += ":";
            res += str;
        }

        return res;
    }

    vector<string> decode(string s) {
        std::size_t index = 0;
        std::vector<string> res;
        while (index < s.size()) {
            auto pos = s.find_first_of(':', index);

            if (pos == std::string::npos) break;

            auto str_size = std::stoi(s.substr(index, pos - index));
            index = pos + 1;

            res.emplace_back(s.substr(index, str_size));

            index += str_size;
        }

        return res;
    }
};
