#include <stdio.h>

int main() {
    int n;
    int a[100][100];
    int flag = 1;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n && flag; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (a[i][j] != 1) {
                    flag = 0;
                    break;
                }
            } else {
                if (a[i][j] != 0) {
                    flag = 0;
                    break;
                }
            }
        }
    }

    if (flag)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
