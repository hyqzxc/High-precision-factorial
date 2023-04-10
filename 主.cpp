#include <stdio.h>
#include <string.h>

#define MAX_N 10000

int res[MAX_N], len = 1;

void factorial(int n) {
    for (int i = 2; i <= n; i++) {
        int carry = 0;
        for (int j = 0; j < len; j++) {
            int temp = res[j] * i + carry;
            res[j] = temp % 10;
            carry = temp / 10;
        }
        while (carry) {
            res[len++] = carry % 10;
            carry /= 10;
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF)
    {
        memset(res, 0, sizeof(res));
        res[0] = 1; factorial(n);
        for (int i = len - 1; i >= 0; i--) {
            printf("%d", res[i]);
        }
        printf("\n");
    }
    return 0;
}
