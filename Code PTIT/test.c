#include <stdio.h>

int f(int *a, int *b) {
    *a = 3;
    *b = 4;
    return *a + *b;
}

int main() {
    int a = 1;
    int b = 2;
    int c = f(&a, &a);
    printf("%d %d %d", a, b, c);
}