#include <stdio.h>

int main() {
    int n;
    long long arr[1000];
    long long prefix[1000];
    long long count = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    prefix[0] = arr[0];

    if (prefix[0] == 0)
        count++;

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
        if (prefix[i] == 0)
            count++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (prefix[j] == prefix[i])
                count++;
        }
    }

    printf("%lld", count);

    return 0;
}