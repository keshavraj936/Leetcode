class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        long long num = x;   

        bool negative = num < 0;

        if (negative) {
            num = -num;
        }

        while (num > 0) {
            int rem = num % 10;
            rev = rev * 10 + rem;
            num /= 10;
        }

        if (negative) {
            rev = -rev;
        }

        if (rev < INT_MIN || rev > INT_MAX) {
            return 0;
        }

        return (int)rev;
    }
};
