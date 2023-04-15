#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main(int argc, char **argv) {
	int fdin, fdout; // descripteurs de fichiers en entrée et en sortie	// buffer utilisée pour les lectures/écritures
	int nbread;	// nombre d'octets lus après chaque appel à read

    unsigned char *buffer = malloc(4096 * sizeof(unsigned char));
	// [1] Ouverture des fichiers en entrée et sortie le nom du fichier à lire est passé en premier argument du programme, le nom du fichier dans lequel écrire le résultat est passé en second argument

	fdin = open(argv[1], O_RDONLY);
	if (fdin == -1) {
        perror("open");
        exit(1);
    }
    fdout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fdout == -1) {
        perror("open");
        exit(1);
    }


	// [2] Lecture de l'entête du fichier en entrée, modification des donnée nécessaires dans le buffer et écriture de l'entête modifié dans le fichier en sortie
	nbread = read(fdin, buffer, 44);
	if (nbread == -1) {
        perror("read");
        exit(1);
    }
    int *p;
    short int *q;
    p = (int *) (buffer + 4);
    *p = *p / 2;
    q = (short int *) (buffer + 22);
    *q = 1;
    p = (int *) (buffer + 28);
    *p = *p / 2;
    q = (short int *) (buffer + 32);
    *q = *q / 2;
    p = (int *) (buffer + 40);
    *p = *p / 2;
    if (write(fdout, buffer, 44) == -1) {
        perror("write");
        exit(1);
    }
	// [3] Lecture des données du fichier en entrée (par blocs de 4096 octets) et écriture dans le fichier en sortie des octets correspondant aux échantillons du premier canal.
    while ((nbread = read(fdin, buffer, 4096)) > 0) {
        for (int i = 0; i < nbread; i += 4) {
            if (write(fdout, buffer + i, 2) == -1) {
                perror("write");
                exit(1);
            }
        }
    }
    if (nbread == -1) {
        perror("read");
        exit(1);
    }
	close(fdin);
	close(fdout);
    free(buffer);
    return 0;
}