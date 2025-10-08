#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int lengthOfLongestSubstring(std::string& s) {
    std::vector<int> last(256, -1);
    int best = 0, l = 0;

    for (int r = 0; r < (int)s.size(); ++r) {
        unsigned char ch = static_cast<unsigned char>(s[r]);
        if (last[ch] >= l)
            l = last[ch] + 1;
        last[ch] = r;
        best = std::max(best, r - l + 1);
    }
    return best;
}

int main() {
    std::string s = "abscbbsbsb";
    int longest = lengthOfLongestSubstring(s);
    std::cout << longest;
    return 0;
}