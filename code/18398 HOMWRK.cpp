#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d %d\n", a + b, a * b);
        }
    }
}