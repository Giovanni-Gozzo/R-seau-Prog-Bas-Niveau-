#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*
 * Ouvre le fichier message.txt du répertoire courant et affiche son contenu à l'écran.
 */
int main() {
    char buffer[256];
    ssize_t byte_read;
    int fd = open("message.txt", O_RDONLY);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    while ((byte_read=read(fd,buffer,256))>0){
        write(1,buffer,byte_read);
    }
    close(fd);
    return EXIT_SUCCESS;
}