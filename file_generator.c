#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define NFILE 1000

int main() {
    
    time_t t;
    srand((unsigned) t ^ getpid());

    char *path = "send";

    for (int i = 0; i < NFILE; i++) {
        char pathname[20];
        sprintf(pathname, "%s/%06d", path, i);
        printf("%06d ", i);

        int fd = creat(pathname, S_IRUSR | S_IWUSR);

        if (fd == -1) {
            perror("creat");
            break;
        }

        int filesize = rand() % 32 + 1;
        printf("Size: %dK\n", filesize);
        char msg[1024];
        for (int j = 0; j < filesize; j++) {

            memset(msg, 0, sizeof(msg));

            for (int k = 0; k < 1023; k++) {
                char ch = rand() % (126-32) + 32;
                msg[strlen(msg)] = ch;
            }
            msg[strlen(msg)] = '\0';

            if (write(fd, msg, strlen(msg)) < 0) {
                perror("write");
                break;
            }
        }

        close(fd);
        
    }

    return 0;
    
}