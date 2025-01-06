class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<string> res;
        unordered_set<char> left;
        vector<int> right(26, 0);

        for (char c : s) {
            right[c - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            right[s[i] - 'a']--;
            if (right[s[i] - 'a'] == 0) {
                right[s[i] - 'a'] = -1;
            }

            for (int j = 0; j < 26; j++) {
                char c = 'a' + j;
                if (left.count(c) && right[j] > 0) {
                    res.insert(string() + s[i] + c);
                }
            }
            left.insert(s[i]);
        }

        return res.size();
    }
};