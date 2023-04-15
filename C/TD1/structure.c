#include <stdio.h>

struct Personne {
    char *nom;
    int age;
    float taille;
};

struct Famille {
    char *nom;
    struct Personne pere;
    struct Personne mere;
    int nb_enfants;
    struct Personne * enfants;
};

int age_total(struct Famille f){
    int total = f.pere.age + f.mere.age;
    for (int i = 0; i < f.nb_enfants; i++){
        total += f.enfants[i].age;
    }
    return total;
}
int main(){
    printf("chaine: %li, entier: %li, flottant: %li, personne: %li, famille: %li\n",
        sizeof (char*),
        sizeof (int),
        sizeof (float),
        sizeof (struct Personne),
        sizeof (struct Famille));

        struct Personne p;
        char nom[] = "Guybrusheyt";
        p.nom = nom;
        p.age = 40;
        p.taille = 1.75;

        struct Personne p2;
        p2.nom = nom;
        p2.age = 41;
        p2.taille = 1.75;

        struct Personne e;
        e.nom = nom;
        e.age = 12;
        e.taille = 1.75;

        struct Personne e2;
        e2.nom = nom;
        e2.age = 8;
        e2.taille = 1.75;

        struct Famille f;
        f.nom = nom;
        f.pere = p;
        f.mere = p2;
        f.nb_enfants = 2;
        struct Personne e3[2] = {e,e2};
        f.enfants = e3;
        printf("%i\n", age_total(f));
};