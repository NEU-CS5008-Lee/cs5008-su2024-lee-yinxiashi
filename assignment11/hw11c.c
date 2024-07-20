// name: Yinxia Shi
// email: shi.yinx@northeastern.edu

#include <stdio.h>

int d[20];

long long int dp(int n) {

    // Add your code here
    if (n % 2 == 1) {
        return 0;
    }

    int m = n / 2;

    if (d[m] != 0) {
        return d[m];
    }
    if (n == 0) {
        d[m] = 1;
    } else {
        d[m] = 3 * dp(n - 2);
        for (int i = n - 4; i >= 0; i -= 2) {
            d[m] += 2 * dp(i);
        }
    }
    return d[m];
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}
