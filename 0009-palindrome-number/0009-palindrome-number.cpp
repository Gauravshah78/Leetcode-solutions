class Solution {
public:
    bool isPalindrome(int x) {
        int lastterm =0, n=x;
        long rev = 0;
        while (n > 0) {
            lastterm = n % 10;
            n/= 10;
            rev = rev * 10 + lastterm;
        }
        if (rev == x)
            return true;
        else
            return false;
    }
};