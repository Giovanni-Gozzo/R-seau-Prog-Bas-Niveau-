//
// Created by starl on 07/02/2023.
//
#include <stdio.h>

int maximum(int *t, int n) {
    int max = *t;
    for (int i = 0; i < n; i++) {
        if (max < *(t + i)) {
            max = *(t + i);
        }
    }
    return max;
}

void f(int a, int b, int *s, int *p) {
    *s = a + b;
    *p = a * b;
}

void minmax(int *t, int n, int *pmin, int *pmax) {
    for (int i = 0; i < n; i++) {
        if (*pmin > *(t + i)) {
            *pmin = *(t + i);
        }
        if (*pmax < *(t + i)) {
            *pmax = *(t + i);
        }
    }
}

void main() {
    int x, y;
    f(12, 4, &x, &y);
    printf("x = %d, y = %d\n", x, y);

    int t[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int min = t[0];
    int max = t[0];
    minmax(t, 10, &min, &max);
    printf("min = %d, max = %d\n", min, max);
}