// name: Yinxia Shi
// email: shi.yinx@northeastern.edu

#include <stdio.h>

int d[20];

long long int dp(int n) {

    // Add your code here
    if (d[n] != 0) {
        return d[n];
    }
    if (n == 1 || n == 0) {
        d[n] = 1;
    } else {
        d[n] = dp(n - 1) + 2 * dp(n - 2);
    }
    return d[n];
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}
