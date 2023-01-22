#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <sys/wait.h>

char* combine_string(char first[], char second[]) {

    char* res = malloc(strlen(first) + strlen(second));
    int k = 0;
    for (int i = 0; i < strlen(first); i++)
        res[k++] = first[i];

    for (int i = 0; i < strlen(second); i++)
        res[k++] = second[i];

    res[k] = '\0';

    return res;

}

int main() {

    int fd = open("test.txt", O_CREAT|O_WRONLY|O_TRUNC);

    printf("fd: %d\n", fd);

    int fRet = fork();

    if (fRet < 0) {
        perror("fork");
        exit(1);
    } 
    else if (fRet == 0) {
        printf("In Child:-\n");
        printf("Original FD: %d\n", fd);
        int new_fd = dup(fd);
        printf("Dup FD: %d\n", new_fd);
        int another_fd = 10;
        printf("Dup2 FD Set to 10 result: %d\n", dup2(fd, another_fd));

        char* str = malloc((int)((ceil(log10(fd))+1)*sizeof(char)));
        sprintf(str, "%d", fd);

        char* arg = combine_string(combine_string("/proc/", str), "/fd");
        free(str);

        char* args[] = {"ls", arg, NULL};
        execvp(args[0], args);

    }
    else {
        wait(NULL);
        printf("In parent.\n");
        printf("FD: %d\n", fd);
    }

    return 0;
}