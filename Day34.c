#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int pop() {
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char expr[100];
    fgets(expr, sizeof(expr), stdin);

    char* token = strtok(expr, " ");

    while (token != NULL) {

        if (isdigit(token[0])) {
            push(atoi(token));
        } 
        else {
            int b = pop();
            int a = pop();
            int res;

            if (token[0] == '+') res = a + b;
            else if (token[0] == '-') res = a - b;
            else if (token[0] == '*') res = a * b;
            else if (token[0] == '/') res = a / b;

            push(res);
        }

        token = strtok(NULL, " ");
    }

    printf("%d", pop());

    return 0;
}