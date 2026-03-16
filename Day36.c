#include <stdio.h>

#define MAX 100

int queue[MAX];

int main() {
    int n;
    scanf("%d", &n);

    int front = 0;
    int rear = -1;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        rear = (rear + 1) % MAX;
        queue[rear] = x;
    }

    int m;
    scanf("%d", &m);

    front = (front + m) % MAX;

    for (int i = 0; i < n; i++) {
        int index = (front + i) % MAX;
        printf("%d ", queue[index]);
    }

    return 0;
}