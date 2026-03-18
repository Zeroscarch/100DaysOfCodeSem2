#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x) {
    int i = size++;
    while (i > 0 && pq[(i - 1) / 2] > x) {
        pq[i] = pq[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq[i] = x;
}

int deleteMin() {
    if (size == 0) return -1;

    int min = pq[0];
    int last = pq[--size];

    int i = 0;
    while (2 * i + 1 < size) {
        int child = 2 * i + 1;
        if (child + 1 < size && pq[child + 1] < pq[child])
            child++;

        if (last <= pq[child]) break;

        pq[i] = pq[child];
        i = child;
    }

    pq[i] = last;
    return min;
}

int peek() {
    if (size == 0) return -1;
    return pq[0];
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } 
        else if (strcmp(op, "delete") == 0) {
            printf("%d\n", deleteMin());
        } 
        else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}