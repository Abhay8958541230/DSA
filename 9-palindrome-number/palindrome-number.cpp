class Solution {
public:
    long long  isPalindrome(int x) {
        if (x < 0)
            return false;

        long long revNum = 0;
        long long dup = x;

        while (x > 0) {
            int ld = x % 10;
            revNum = revNum * 10 + ld;
            x /= 10;
        }

        return dup == revNum;
    }
};