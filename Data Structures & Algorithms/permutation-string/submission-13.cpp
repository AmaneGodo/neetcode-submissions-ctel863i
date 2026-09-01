class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> count_s1(26, 0);
        vector<int> count_s2(26, 0);

        for (int i = 0; i < s1.length(); i++) {
            count_s1[tolower(s1[i]) - 'a']++;
            count_s2[tolower(s2[i]) - 'a']++;
        }

        if (count_s1 == count_s2) {
            return true;
        }

        int l = 0;
        for (int r = s1.length(); r < s2.length(); r++) {
            count_s2[tolower(s2[r]) - 'a']++;
            count_s2[tolower(s2[l]) - 'a']--;
            l++;

            if (count_s1 == count_s2) {
                return true;
            }
        }

        return false;
    }
};
