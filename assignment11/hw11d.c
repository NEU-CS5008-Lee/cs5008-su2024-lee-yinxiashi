// name: Yinxia Shi
// email: shi.yinx@northeastern.edu

#include <stdio.h>

int d[20];

long long int dp(int n) {

    // Add your code here
    if (d[n] != 0) {
        return d[n];
    }
    if (n == 0) {
        d[n] = 1;
    } else if (n == 1) {
        d[n] = 2;
    } else {
        d[n] = 3 * dp(n - 2) + 2 * dp(n - 1);
        for (int i = n - 3; i >= 0; i--) {
            d[n] += 2 * dp(i);
        }
    }
    return d[n];
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}
