class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        std::vector<int> count_s1(26, 0), count_s2(26, 0);
        int l = 0;
        
        for (int i = 0; i < s1.length(); i++) {
            count_s1[s1[i] - 'a']++;
            count_s2[s2[i] - 'a']++;
        }

        if (count_s1 == count_s2) {
            return true;
        }

        for (int r = s1.length(); r < s2.length(); r++) {
            count_s2[s2[r] - 'a']++;
            count_s2[s2[l] - 'a']--;

            if (count_s2 == count_s1) {
                return true;
            }

            l++;
        }

        return false;
    }
};
