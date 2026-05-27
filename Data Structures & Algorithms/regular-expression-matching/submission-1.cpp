#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        const int n = s.size();
        const int m = p.size();

        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

        return matches(s, p, 0, 0, memo);
    }

private:
    bool matches(const string& s,
                 const string& p,
                 int sIndex,
                 int pIndex,
                 vector<vector<int>>& memo) {

        if (memo[sIndex][pIndex] != -1) {
            return memo[sIndex][pIndex];
        }

        const int sLength = s.size();
        const int pLength = p.size();

        // Pattern fully consumed
        if (pIndex == pLength) {
            return memo[sIndex][pIndex] = (sIndex == sLength);
        }

        bool firstMatch =
            (sIndex < sLength) &&
            (s[sIndex] == p[pIndex] || p[pIndex] == '.');

        bool result = false;

        // Handle '*'
        if (pIndex + 1 < pLength && p[pIndex + 1] == '*') {

            // Option 1: skip current pattern block
            bool skipPattern =
                matches(s, p, sIndex, pIndex + 2, memo);

            // Option 2: consume one character
            bool consumeCharacter =
                firstMatch &&
                matches(s, p, sIndex + 1, pIndex, memo);

            result = skipPattern || consumeCharacter;
        }
        else {
            result =
                firstMatch &&
                matches(s, p, sIndex + 1, pIndex + 1, memo);
        }

        memo[sIndex][pIndex] = result;
        return result;
    }
};