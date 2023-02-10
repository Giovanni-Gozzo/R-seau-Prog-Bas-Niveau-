#include <stdio.h>
#include <string.h>
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
    struct Personne *enfants;
};

int age_total(struct Famille fm){
    int lg=fm.nb_enfants;
    int res=fm.pere.age+fm.mere.age;
    for(int i=0;i<lg;i++){
        res+=fm.enfants[i].age;
    }
    return res;
}

int main(){
    struct Famille fm;

    struct Personne mer;
    mer.age=30;
    mer.nom="maman";
    mer.taille=120;

    struct Personne per;
    per.age=20;
    per.nom="pere";
    per.taille=150;

    struct Personne tmp[] = {{"gia",10,170}, {"gio",5,190}} ;
    fm.mere=mer;
    fm.pere=per;
    fm.nb_enfants=2;
    fm.enfants=tmp;
    fm.nom="Gozzo";
    printf("%i",age_total(fm));
};