//
// Created by starl on 07/02/2023.
//
#include <stdio.h>

struct Matrice {
    int nb_lignes;
    int nb_colonnes;
    int **valeurs;
};

void affiche(struct Matrice m) {
    for (int i = 0; i < m.nb_lignes; i++) {
        for (int j = 0; j < m.nb_colonnes; j++) {
            printf("%d ", m.valeurs[i][j]);
        }
        printf("\n");
    }
}

struct Matrice matrice(int nbl, int nbc, int *valeurs){
    struct Matrice m;
    m.nb_lignes = nbl;
    m.nb_colonnes = nbc;
    m.valeurs = malloc(sizeof(int*) * nbl);
    for (int i = 0; i < nbl; i++) {
        m.valeurs[i] = malloc(sizeof(int) * nbc);
        for (int j = 0; j < nbc; j++) {
            m.valeurs[i][j] = *(valeurs + i * nbc + j);
        }
    }
    return m;
}

void efface(struct Matrice m){
    for (int i = 0; i < m.nb_lignes; i++) {
        free(m.valeurs[i]);
    }
    free(m.valeurs);
}


struct Matrice multiplie(struct Matrice m1, struct Matrice m2){
    struct Matrice m;
    m.nb_lignes = m1.nb_lignes;
    m.nb_colonnes = m2.nb_colonnes;
    m.valeurs = malloc(sizeof(int *) * m.nb_lignes);
    for (int i = 0; i < m.nb_lignes; i++) {
        m.valeurs[i] = malloc(sizeof(int) * m.nb_colonnes);
        for (int j = 0; j < m.nb_colonnes; j++) {
            m.valeurs[i][j] = 0;
            for (int k = 0; k < m1.nb_colonnes; k++) {
                m.valeurs[i][j] += m1.valeurs[i][k] * m2.valeurs[k][j];
            }
        }
    }
    return m;
}

int main() {
    int v1[12] = {
            1, 2, 3, 4,
            2, 4, 6, 8,
            3, 6, 9, 12,
    };
    struct Matrice m1 = matrice(3, 4, v1);
    affiche(m1);
    //efface v1
    int v2[12] = {
            1, 2, 3,
            2, 4, 6,
            3, 6, 9,
            4, 8, 12,
    };
    struct Matrice m2 = matrice(4, 3, v2);
    printf("---------------------------------------------\n");
    affiche(m2);
    printf("---------------------------------------------\n");
    struct Matrice m3 = multiplie(m1, m2);
    affiche(m3);
    printf("---------------------------------------------\n");
    efface(m1);
}