#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
/**
 * Copie le contenu du fichier message.txt dans un fichier copie.txt
 * Écrivez le programme copy.c qui copie le contenu du fichier message.txt dans un fichier copie.txt.

   Indication : Il faut ouvrir le premier fichier en lecture et le second en écriture (en le créant si nécessaire) et copier le contenu du premier dans le second.

   Attention : Si le fichier de destination n'existe pas, il faut le créer en lui donnant des permissions. Ces permissions sont données à la fonction open en quatrième argument. Vous pouvez utiliser la notation en octal comme pour la fonction chmod (par exemple 0644) ou utiliser des flags, dont vous trouverez le détail dans la page de manuel de open.
 */
 // use open, close, read, write et lseek.
int main(int argc, char **argv) {
    if (argc != 3) {
        perror("You have to give 2 arguments");
        exit(1);
    }
    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd1 == -1 || fd2 == -1) {
        perror("open");
        exit(1);
    }
    char *buffer = malloc(1024 * sizeof(char));
    int n;
    while ((n = read(fd1, buffer, 1024)) > 0) {
        write(fd2, buffer, n);
    }
    close(fd1);
    close(fd2);
    free(buffer);
    return 0;
}