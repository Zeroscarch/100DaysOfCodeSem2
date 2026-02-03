#include <stdio.h>

int main() {
    int n, k;
    int a[100];
    int comparisons = 0;
    int found = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &k);

    for(int i = 0; i < n; i++) {
        comparisons++;
        if(a[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Not Found\n");
    }

    printf("Comparisons = %d", comparisons);

    return 0;
}
