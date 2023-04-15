#include <stdio.h>
int main() {
    char chaine[80];
    printf("Entrez une chaîne: ");
    fgets(chaine, 80, stdin);
    fputs(chaine, stdout);
}