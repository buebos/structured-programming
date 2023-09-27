#include <stdio.h>

/** O(log(min(a, b))) */
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

/** O(min(a, b)) */
int gcdSlow(int a, int b, int current, int i) {
    if (i > a || i > b) {
        return current;
    }

    if (a % i == 0 && b % i == 0) {
        return gcdSlow(a, b, i, i + 1);
    } else {
        return gcdSlow(a, b, current, i + 1);
    }
}

int main() {
    printf("GCD fast: %d\n", gcd(12, 36));
    printf("GCD slow: %d", gcdSlow(12, 36, 0, 1));

    return 0;
}