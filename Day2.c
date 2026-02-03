#include <stdio.h>

int main() {
    int n, pos;
    int a[100];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &pos);

    for(int i = pos - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    for(int i = 0; i < n - 1; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
