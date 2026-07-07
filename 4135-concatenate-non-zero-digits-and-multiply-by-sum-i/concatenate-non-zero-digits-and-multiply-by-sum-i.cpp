class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0, p = 1;
        while (n > 0) {
            int d = n % 10;
            if (d != 0) {
                x += 1LL * d * p;
                p *= 10;
                sum += d;
            }
            n /= 10;
        }
        return x * sum;
    }
};