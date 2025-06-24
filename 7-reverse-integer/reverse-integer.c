#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    long reversed = 0;

    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        // Check for potential overflow before multiplying
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7)) return 0;
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8)) return 0;

        reversed = reversed * 10 + digit;
    }
    return (int)reversed;
}