class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t pos;
        while ((pos = s.find(part)) != std::string::npos) { // Find substring
            s.erase(pos, part.length()); // Erase substring
        }
        return s;
    }
};
