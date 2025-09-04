#include <string>
#include <vector>
#include <algorithm>

class LongestSubString {
public:
    int lengthOfLongestSubstring(std::string& s) {
        std::vector<int> last(256, -1); // ASCII lookup
        int best = 0, l = 0;

        for (int r = 0; r < (int)s.size(); ++r) {
            unsigned char ch = static_cast<unsigned char>(s[r]);
            if (last[ch] >= l)
                l = last[ch] + 1; // jump left past previous same char
            last[ch] = r;
            best = std::max(best, r - l + 1);
        }
        return best;
    }
};