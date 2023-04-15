//
// Created by starl on 07/02/2023.
//
#include <stdio.h>
#include <malloc.h>

//Pour résoudre ce problème, on pourrait passer en argument de la fonction un pointeur vers un emplacement de mémoire réservé à l'avance, comme on l'a fait précédemment, mais une autre solution consiste à allouer un espace mémoire dans le tas, qui ne sera donc pas libéré à la fin de la fonction.
//Pour cela, on utilise la fonction malloc qui prend comme argument la taille de la mémoire à allouer (en octets) et renvoie l'adresse d'un pointeur vers cet espace. Ainsi, si l'on veut assez de place pour stocker n objets de type int, on peut utiliser la syntaxe :
//int *p;
//p = malloc(sizeof(int) * n);
//int* copieTab(int *t, int n) {

int* copie(int *t, int n) {
    int *p;
    p = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        *(p + i) = *(t + i);
    }
    return p;
}


int* unsurdeux(int *t, int n) {
    int *p;
    p = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        *(p + i) = *(t + i) / 2;
    }
    return p;
}

int main() {
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *tab_bis;

    tab_bis = unsurdeux(tab, 10);
    for (int i = 0; i < 5; i++) {
        printf("%i ", tab_bis[i]);
    }
    printf("\n");
    free(tab_bis);
}