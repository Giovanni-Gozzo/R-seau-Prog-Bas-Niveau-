#include <stdio.h>
#include <mm_malloc.h>
struct Matrice {
    int nb_lignes;
    int nb_colonnes;
    int **valeurs;
};
int* copie(int *tab, int n) {
    int *tab3= malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        tab3[i] = tab[i];
    }
    return tab3;
}

void affiche(struct Matrice m){
    for(int i=0;i<m.nb_lignes;i++){
        if(i>0){
            printf("\n");
        }
        for(int j=0;j<m.nb_colonnes;j++){
            printf("%i ",m.valeurs[i][j]);
        }
        }
}
struct Matrice matrice(int nbl, int nbc, int *valeurs){
    int **mat= malloc(sizeof(int*)*nbl);
    int *lig= malloc(sizeof(int)*nbc);
    int j=0;
    int z=0;
    for(int i=0;i<(nbl*nbc);i++){
        lig[j]=valeurs[i];
        j++;
        if(j>=nbc){
            j=0;
            mat[z]=copie(lig,nbc);
            z++;
        }
    }
    struct Matrice m;
    m.valeurs=mat;
    m.nb_colonnes=nbc;
    m.nb_lignes=nbl;
    return m;
}
void efface(struct Matrice m){
    int i;
    for (i = 0; i < m.nb_lignes; i++) {
        free(m.valeurs[i]);
    }
    free(m.valeurs);
}
struct Matrice multiplie(struct Matrice m1, struct Matrice m2){
    int **m= malloc(sizeof(int*)*m1.nb_lignes);
    int *lig= malloc(sizeof (int)*m2.nb_colonnes);
    int val=0;
    for(int i=0;i<m1.nb_lignes;i++){
        for(int j=0;j<m1.nb_colonnes;j++){
            for(int z=0;z<m2.nb_lignes;z++){
                val+=m1.valeurs[i][z]+m2.valeurs[z][j];
            }
            lig[j]=val;
            val=0;
        }
        m[i]= copie(lig,m2.nb_colonnes);
    }
    struct Matrice res;
    res.nb_lignes=m1.nb_lignes;
    res.nb_colonnes=m2.nb_colonnes;
    res.valeurs=m;
    return res;
}

int main(){
    int v1[12] = {
            1, 2, 3, 4,
            2, 4, 6, 8,
            3, 6, 9, 12,
    };
    int v2[12] = {
            1, 2, 3, 4,
            2, 4, 6, 8,
            3, 6, 9, 12,
            4,8,12,16,
    };
    struct Matrice m1 = matrice(3, 4, v1);
    struct Matrice m2 = matrice(4, 4, v2);

    affiche(multiplie(m1,m2));
}
