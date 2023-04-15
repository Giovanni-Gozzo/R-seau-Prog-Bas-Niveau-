#include <stdio.h>

#define MESSAGE "Super\n"

int dbl(int a) {
    return a * 2;
}

int main() {
    int tab[3];
    tab[0]=5;
    tab[1]=2;
    printf("valeur du tableau\n");
    for(int i = 0; i < 4; i++ ){
        printf("%i\n", tab[i]);
    }
    printf(MESSAGE);
    printf("résultat: %i\n", dbl(4));
}

//Combien d'espace mémoire occupe la chaîne de caractères "Youpi\n" ?
// 7 car Y o u p i \0 \n