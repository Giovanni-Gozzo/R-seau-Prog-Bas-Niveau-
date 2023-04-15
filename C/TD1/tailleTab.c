#include <stdio.h>

int main() {
    int t[2];
    printf("Premiere adresse: %lu,\nseconde adresse: %lu\n",
        (long unsigned) t, // adresse de t[0]
        (long unsigned) (t+1)); // adresse de t[1]
}