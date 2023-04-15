#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int lireligne(int fd, char *buffer, int size) {
    ssize_t nbread = read(fd, buffer, size);
    if (nbread == -1) {
        return -1;
    }

    int i;
    for (i = 0; i < nbread; i++) {
        if (buffer[i] == '\n') {
            i++;
            break;
        }
    }
    lseek(fd, i - nbread, SEEK_CUR);
    return i;
}


int main(int argc, char **argv) {
    int fd_in;  // descripteur de fichier du fichier ouvert en lecture
    int fd_out; // descripteur de fichier du fichier ouvert en écriture
    int nbread;
    unsigned char *buffer = malloc(4096 * sizeof(unsigned char));    // buffer de lecture

    if (argc != 3) {
        perror("le nombre passer en argument est incorrect");
        exit(1);
    }

    fd_in = open(argv[1], O_RDONLY);
    if (fd_in == -1) {
        perror("open");
        exit(1);
    }

    fd_out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd_out == -1) {
        perror("open");
        exit(1);
    }
    int n;

    for (int i = 0 ; i < 3 ; i++){
        n = lireligne(fd_in, buffer, 4096);
        write(fd_out, buffer, n);
    }

    while ((nbread = lireligne(fd_in, buffer, 4096)) > 0) {
        for (int i = 0; i < nbread; i++) {
            buffer[i] = 255 - buffer[i];
        }
        write(fd_out, buffer, nbread);
    }

    close(fd_in);
    close(fd_out);
    free(buffer);

    return 0;
}