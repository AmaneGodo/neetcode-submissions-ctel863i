class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;

        while (i < j) {
            while ((i < j) && (!isAlNum(tolower(s[i])))) {
                i++;
            }

            while ((i < j) && (!isAlNum(tolower(s[j])))) {
                j--;
            }

            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++;
            j--;
        }

        return true;

    }

    bool isAlNum(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            return true;
        } else {
            return false;
        }
    }
};
