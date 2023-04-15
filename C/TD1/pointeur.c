#include <stdio.h>
int main() {
    int a, *b; // allouer un emplacement memoir pour a et b
    a = 12; // met la memoire allouer de a a 12
    b = &a; // met la valeur de la memoire de b a la valeur de la memoire de a
    *b = a + 1; // ajoute 1 a la valeur de a par le moyen de b
    printf("a = %i, b = %lu\n", a, (long unsigned)b);
    printf("adresse de a = %lu\n",(long unsigned)&a);
    printf("----------------------------------------------------------\n");
    printf("a = %i, b = %p\n", a, b);
    printf("adresse de a = %p\n",&a);

}