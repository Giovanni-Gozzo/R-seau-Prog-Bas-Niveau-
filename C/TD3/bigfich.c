#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
/**
 * Prend en argument une liste de noms de fichiers et affiche le nom du plus grand d'entre eux.
 * Le nombre de noms de fichiers passé en argument doit être au moins 1 mais peut être arbitrairement grand.
 */

int main(int argc, char *argv[]) {
    if (argc < 2) {
        perror("le nombre passer en argument est incorrect");
        exit(1);
    }
    struct stat buf;
    char *biggest_file = NULL;
    off_t max_size = 0;

    for (int i = 1; i < argc; i++) {
        if (stat(argv[i], &buf) != 0) {
            perror(argv[i]);
        }

        if (!S_ISREG(buf.st_mode)) {
            perror("Ce n'est pas un fichier valide");
        }

        if (buf.st_size > max_size) {
            max_size = buf.st_size;
            biggest_file = argv[i];
        }
    }

    if (biggest_file == NULL) {
        perror("Il n'y a pas de fichier");
    } else {
        printf("Le plus gros fichier est: %s\n", biggest_file);
    }

    return 0;
}