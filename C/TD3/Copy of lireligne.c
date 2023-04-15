#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>
/**
 * Lit une ligne du fichier correspondant au descripteur passé en argument jusqu'à lire un retour à la ligne ('\n') ou
 * avoir lu size caractères.
 *
 * @param fd descripteur de fichier ouvert en lecture
 * @param s buffer dans lequel les octets lus sont écrits
 * @param size nombre maximum d'octets à lire
 * @return le nombre d'octets effectivement lus
 */
#include <unistd.h>

int lireligne(int fd, char *s, int size) {
    int i = 0;
    char c[1];
    ssize_t nbread;
    do {
        nbread = read(fd, c, 1);
        if (nbread < 1) {
            break;
        }
        s[i] = *c;
        i++;
    } while (i < size && *c != '\n');

    if (i == 0) {
        return -1;
    }

    s[i] = '\0';

    if (*c != '\n') {
        lseek(fd, i - nbread, SEEK_CUR);
    }

    return i;
}

int main() {
    int fd;
    char buffer[1024];
    int n;

    fd = open("message.txt", O_RDONLY);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    n = lireligne(fd, buffer, sizeof(buffer));
    printf("%d caractères lus : %s\n", n, buffer);
    n = lireligne(fd, buffer, sizeof(buffer));
    printf("%d caractères lus : %s\n", n, buffer);

    if (n == -1) {
        perror("Erreur lors de la lecture du fichier");
        exit(EXIT_FAILURE);
    }

    close(fd);
}
